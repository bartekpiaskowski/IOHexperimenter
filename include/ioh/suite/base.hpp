/// \file suite.h
/// \brief Header file for the template class suite.
///
/// \author Furong Ye
#pragma once

#include "ioh/problem/base.hpp"
#include "ioh/common/class_generator.hpp"

namespace ioh
{
	namespace suite
	{
		/// \brief A base class for construct a suite for sets of problem::bases.
		///
		/// To specify available problems of a suite, registerProblem must be implemented in derived class.
		/// The default lable of problems are string type. Integer type are also optional, but we highly
		/// recommond registering problem with string lable and creating a map of string problem_name and integer problem_id.
		template <typename T>
		class base : public problem::base<T>, public std::vector<std::shared_ptr<problem::base<T>>>
		{
			typedef std::shared_ptr<problem::base<T>> Problem_ptr;

			std::string suite_name;
			int number_of_problems;
			int number_of_instances;
			int number_of_dimensions;

			std::vector<int> problem_id;
			std::vector<int> instance_id;
			std::vector<int> dimension;

			std::map<int, std::string> problem_id_name_map;
			std::map<std::string, int> problem_name_id_map;

			size_t problem_list_index;
			size_t size_of_problem_list;
			bool get_problem_flag;
			bool load_problem_flag;

			Problem_ptr current_problem;
		public:
			base(std::vector<int> problem_id = std::vector<int>(0), std::vector<int> instance_id = std::vector<int>(0),
			     std::vector<int> dimension = std::vector<int>(0)) :
				suite_name("no suite"),
				problem_id(problem_id),
				instance_id(instance_id),
				dimension(dimension),
				problem_list_index(0),
				size_of_problem_list(0),
				get_problem_flag(false),
				load_problem_flag(false),
				current_problem(nullptr),
				number_of_dimensions(0),
				number_of_problems(0),
				number_of_instances(0)
			{
				std::cout << "Is this called? " << std::endl;
			}

			base(const base&) = delete;
			base& operator =(const base&) = delete;

			/// \fn virtual void registerProblem()
			/// \brief A virtual function for registering problems.
			///
			/// This function implements interfaces of available problems of a suite. With those interface,
			/// user are able to request problem together with problem_id, instance_id, and dimension.
			virtual void registerInSuite()
			{
			}

			/// \fn loadProblems()
			/// \brief Allocating memeory and creating instances of problems to be included in the suite.
			///
			/// Before acquiring a problem from the suite, this function must be invoked.
			/// Otherwise the list of problem is empty.
			void loadProblem()
			{
				if (this->size() != 0)
				{
					this->clear();
				}
				this->size_of_problem_list = this->number_of_dimensions * this->number_of_instances * this->
					number_of_problems;
				this->problem_list_index = 0;

				for (auto i = 0; i != this->number_of_problems; ++i)
				{
					for (auto j = 0; j != this->number_of_dimensions; ++j)
					{
						for (auto h = 0; h != this->number_of_instances; ++h)
						{
							Problem_ptr p = get_problem(this->problem_id_name_map[this->problem_id[i]],
							                            this->instance_id[h],
							                            this->dimension[j]);
							this->push_back(p);
						}
					}
				}
				assert(this->size_of_problem_list == this->size());
				this->get_problem_flag = false;
				this->load_problem_flag = true;
			}

			/// \fn std::shared_ptr<problem::base<T>> get_next_problem()
			/// \brief An interface of requesting problems in suite.
			///
			/// To request 'the next' problem in the suite of corresponding problem_id, instance_id and dimension index.
			Problem_ptr get_next_problem()
			{
				if (this->load_problem_flag == false)
				{
					this->loadProblem();
				}

				if (this->size_of_problem_list == 0)
				{
					common::log::warning("There is no problem in the suite");
					return nullptr;
				}

				if (this->problem_list_index == this->size_of_problem_list - 1 && this->get_problem_flag == true)
				{
					return nullptr;
				}

				if (this->get_problem_flag == false)
				{
					this->get_problem_flag = true;
				}
				else
				{
					++this->problem_list_index;
				}
				this->current_problem = (*this)[problem_list_index];

				this->current_problem->reset_problem();
				return this->current_problem;
			}

			/// \fn std::shared_ptr<problem::base<T>> get_current_problem()
			/// \brief An interface of requesting problems in suite.
			///
			/// To request 'the current' problem in the suite of correponding problem_id, instance_id and dimension index.
			Problem_ptr get_current_problem()
			{
				if (this->load_problem_flag == false)
				{
					this->loadProblem();
				}

				if (this->get_problem_flag == false)
				{
					this->get_problem_flag = true;
				}
				this->current_problem = (*this)[this->problem_list_index];
				this->current_problem->reset_problem();
				return this->current_problem;
			}


			/// \fn Problem_ptr get_next_problem()
			/// \brief An interface of requesting problems in suite.
			///
			/// To request a specific problem with corresponding problem_id, instance_id and dimension,
			/// without concerning the order of testing problems.
			Problem_ptr get_problem(std::string problem_name, int instance, int dimension)
			{
				Problem_ptr p = common::genericGenerator<problem::base<T>>::instance().create(problem_name);
				assert(p != nullptr);
				p->reset_problem();
				p->set_problem_id(this->problem_name_id_map[problem_name]);
				p->set_instance_id(instance);
				p->set_number_of_variables(dimension);
				return p;
			}

			/// \fn Problem_ptr get_next_problem()
			/// \brief An interface of requesting problems in suite.
			///
			/// To request a specific problem with corresponding problem_id, instance_id and dimension,
			/// without concerning the order of testing problems.
			Problem_ptr get_problem(int problem_id, int instance, int dimension)
			{
				Problem_ptr p = common::genericGenerator<problem::base<T>>::instance().create(
					this->problem_id_name_map[problem_id]);
				assert(p != nullptr);
				p->reset_problem();
				p->set_problem_id(problem_id);
				p->set_instance_id(instance);
				p->set_number_of_variables(dimension);
				return p;
			}

			int get_number_of_problems() const
			{
				return this->number_of_problems;
			}


			int get_number_of_instances() const
			{
				return this->number_of_instances;
			}


			int get_number_of_dimensions() const
			{
				return this->number_of_dimensions;
			}


			std::vector<int> get_problem_id() const
			{
				return this->problem_id;
			}

			std::map<int, std::string> get_problem_name() const
			{
				return this->problem_id_name_map;
			}

			//! Return a map of problem name to problem ID, for all the registered problem.
			std::map<std::string, int> get_problems() const
			{
				return this->problem_name_id_map;
			}

			std::vector<int> get_instance_id() const
			{
				return this->instance_id;
			}

			std::vector<int> get_dimension() const
			{
				return this->dimension;
			}

			std::string get_suite_name() const
			{
				return this->suite_name;
			}

			void set_suite_problem_id(const std::vector<int>& problem_id)
			{
				common::compare_vector(problem_id, this->problem_id);
				this->number_of_problems = static_cast<int>(this->problem_id.size());
			}

			void set_suite_instance_id(const std::vector<int>& instance_id)
			{
				common::compare_vector(instance_id, this->instance_id);
				this->number_of_instances = static_cast<int>(this->instance_id.size());
			}

			void set_suite_dimension(const std::vector<int>& dimension)
			{
				common::compare_vector(dimension, this->dimension);
				this->number_of_dimensions = static_cast<int>(this->dimension.size());
			}


			void set_suite_name(std::string suite_name)
			{
				this->suite_name = suite_name;
			}

			void mapIDTOName(int id, std::string name)
			{
				problem_id_name_map[id] = name;
				problem_name_id_map[name] = id;
			}
		};
	}
}