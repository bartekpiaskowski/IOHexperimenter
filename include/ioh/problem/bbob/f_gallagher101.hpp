/// \file f_gallagher21.hpp
/// \brief cpp file for class f_gallagher21.
///
/// A detailed file description.
/// Refer "https://github.com/numbbo/coco/blob/master/code-experiments/src/f_gallagher.c"
///
/// \author Furong Ye
/// \date 2019-09-12
#pragma once
#include "bbob_base.hpp"

namespace ioh
{
	namespace problem
	{
		namespace bbob
		{
			class Gallagher101 : public bbob_base
			{
				typedef struct f_gallagher_permutation_t1
				{
					double value;
					size_t index;
				} F_GALLAGHER_PERMUTATION_T1;


				static int f_gallagher_compare_doubles1(const void* a, const void* b)
				{
					auto temp = (*(f_gallagher_permutation_t1*)a).value - (*(f_gallagher_permutation_t1*)b).value;
					if (temp > 0)
						return 1;
					if (temp < 0)
						return -1;
					return 0;
				}

				const size_t number_of_peaks = 101;
				std::vector<std::vector<double>> rotation;
				std::vector<std::vector<double>> arr_scales;
				std::vector<std::vector<double>> x_local;
				std::vector<double> peak_values;


			public:
				Gallagher101(int instance_id = DEFAULT_INSTANCE, int dimension = DEFAULT_DIMENSION)
					: bbob_base(21, "Gallagher101", instance_id)
				{
					set_number_of_variables(dimension);
				}


				void prepare_bbob_problem(std::vector<double>& xopt, std::vector<std::vector<double>>& M,
				                          std::vector<double>& _, std::vector<std::vector<double>>& rot1,
				                          std::vector<std::vector<double>>& rot2,
				                          const long rseed, const long n
				) override
				{
					size_t i, j, k;
					auto maxcondition = 1000.;
					/* maxcondition1 satisfies the old code and the doc but seems wrong in that it is, with very high
					* probability, not the largest condition level!!! */
					auto maxcondition1 = 1000.;
					std::vector<double> arrCondition;
					double fitvalues[2] = {1.1, 9.1};
					/* Parameters for generating local optima. In the old code, they are different in f21 and f22 */
					double b, c;
					/* Random permutation */
					//std::vector<f_gallagher_permutation_t1> rperm;
					f_gallagher_permutation_t1* rperm;

					std::vector<double> random_numbers;
					arr_scales = std::vector<std::vector<double>>(number_of_peaks);
					for (i = 0; i != number_of_peaks; ++i)
					{
						arr_scales[i] = std::vector<double>(n);
					}

					x_local = std::vector<std::vector<double>>(n);
					for (i = 0; i != n; ++i)
					{
						x_local[i] = std::vector<double>(number_of_peaks);
					}

					/* Allocate temporary storage and space for the rotation matrices */

					maxcondition1 = sqrt(maxcondition1);
					b = 10.;
					c = 5.;

					transformation::coco::bbob2009_compute_rotation(rotation, rseed, n);

					/* Initialize all the data of the inner problem */
					transformation::coco::bbob2009_unif(random_numbers, number_of_peaks - 1, rseed);
					//rperm = std::vector<f_gallagher_permutation_t1> (number_of_peaks - 1);
					rperm = static_cast<f_gallagher_permutation_t1*>(malloc(
						(number_of_peaks - 1) * sizeof(f_gallagher_permutation_t1)));
					
					for (i = 0; i < number_of_peaks - 1; ++i)
					{
						rperm[i].value = random_numbers[i];
						rperm[i].index = i;
					}
					//std::sort(rperm.begin(), rperm.end(), compareRperm);
					qsort(rperm, number_of_peaks - 1, sizeof(f_gallagher_permutation_t1), f_gallagher_compare_doubles1);

					/* Random permutation */
					arrCondition = std::vector<double>(number_of_peaks);
					arrCondition[0] = maxcondition1;
					peak_values = std::vector<double>(number_of_peaks);
					peak_values[0] = 10;
					for (i = 1; i < number_of_peaks; ++i)
					{
						arrCondition[i] = pow(maxcondition,
						                      static_cast<double>(rperm[i - 1].index) / static_cast<double>(
							                      number_of_peaks - 2));
						peak_values[i] = static_cast<double>(i - 1) / static_cast<double>(number_of_peaks - 2) * (
								fitvalues[1] - fitvalues[0])
							+ fitvalues[0];
					}

					free(rperm);
					rperm = static_cast<f_gallagher_permutation_t1*>(malloc((n) * sizeof(f_gallagher_permutation_t1)));

					//rperm = std::vector<f_gallagher_permutation_t1> (n);
					for (i = 0; i < number_of_peaks; ++i)
					{
						transformation::coco::bbob2009_unif(random_numbers, n, rseed + static_cast<long>(1000 * i));
						for (j = 0; j < n; ++j)
						{
							rperm[j].value = random_numbers[j];
							rperm[j].index = j;
						}
						//std::sort(rperm.begin(), rperm.end(), compareRperm);
						qsort(rperm, n, sizeof(f_gallagher_permutation_t1), f_gallagher_compare_doubles1);
						for (j = 0; j < n; ++j)
						{
							arr_scales[i][j] = pow(arrCondition[i], /* Lambda^alpha_i from the doc */
							                       static_cast<double>(rperm[j].index) / static_cast<double>(n - 1) -
							                       0.5);
						}
					}
					free(rperm);
					transformation::coco::bbob2009_unif(random_numbers, n * number_of_peaks, rseed);
					std::vector<double> best_variables(n);
					for (i = 0; i < n; ++i)
					{
						xopt[i] = 0.8 * (b * random_numbers[i] - c);
						best_variables[i] = 0.8 * (b * random_numbers[i] - c);
						for (j = 0; j < number_of_peaks; ++j)
						{
							x_local[i][j] = 0.;
							for (k = 0; k < n; ++k)
							{
								x_local[i][j] += rotation[i][k] * (b * random_numbers[j * n + k] - c);
							}
							if (j == 0)
							{
								x_local[i][j] *= 0.8;
							}
						}
					}
					set_best_variables(best_variables);
				}


				double internal_evaluate(const std::vector<double>& x) override
				{
					auto n = x.size();

					size_t i, j; /* Loop over dim */
					std::vector<double> tmx(n);
					auto a = 0.1;
					double tmp2, f = 0., f_add, tmp, f_pen = 0., f_true = 0.;
					double fac;

					fac = -0.5 / static_cast<double>(n);

					/* Boundary handling */
					for (i = 0; i < n; ++i)
					{
						tmp = fabs(x[i]) - 5.;
						if (tmp > 0.)
						{
							f_pen += tmp * tmp;
						}
					}
					f_add = f_pen;
					/* Transformation in search space */
					/* TODO: this should rather be done in f_gallagher */

					for (i = 0; i < n; i++)
					{
						tmx[i] = 0;
						for (j = 0; j < n; ++j)
						{
							tmx[i] += rotation[i][j] * x[j];
						}
					}
					/* Computation core*/
					for (i = 0; i < number_of_peaks; ++i)
					{
						tmp2 = 0.;
						for (j = 0; j < n; ++j)
						{
							tmp = (tmx[j] - x_local[j][i]);
							tmp2 += arr_scales[i][j] * tmp * tmp;
						}
						tmp2 = peak_values[i] * exp(fac * tmp2);
						f = f > tmp2 ? f : tmp2;
					}

					f = 10. - f;
					if (f > 0)
					{
						f_true = log(f) / a;
						f_true = pow(exp(f_true + 0.49 * (sin(f_true) + sin(0.79 * f_true))), a);
					}
					else if (f < 0)
					{
						f_true = log(-f) / a;
						f_true = -pow(exp(f_true + 0.49 * (sin(0.55 * f_true) + sin(0.31 * f_true))), a);
					}
					else
					{
						f_true = f;
					}

					f_true *= f_true;
					f_true += f_add;

					return f_true;
				}

				static Gallagher101* createInstance(int instance_id = DEFAULT_INSTANCE,
				                                    int dimension = DEFAULT_DIMENSION)
				{
					return new Gallagher101(instance_id, dimension);
				}
			};
		}
	}
}