// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// cpp_init_suite
int cpp_init_suite(String suite_name, const std::vector<int>& problem_id, const std::vector<int>& instance_id, const std::vector<int>& dimension);
RcppExport SEXP _IOHexperimenter_cpp_init_suite(SEXP suite_nameSEXP, SEXP problem_idSEXP, SEXP instance_idSEXP, SEXP dimensionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< String >::type suite_name(suite_nameSEXP);
    Rcpp::traits::input_parameter< const std::vector<int>& >::type problem_id(problem_idSEXP);
    Rcpp::traits::input_parameter< const std::vector<int>& >::type instance_id(instance_idSEXP);
    Rcpp::traits::input_parameter< const std::vector<int>& >::type dimension(dimensionSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_init_suite(suite_name, problem_id, instance_id, dimension));
    return rcpp_result_gen;
END_RCPP
}
// cpp_init_logger
int cpp_init_logger(String output_directory, String result_folder, String algorithm_name, String algorithm_info, bool dat, bool cdat, int tdat, int idat);
RcppExport SEXP _IOHexperimenter_cpp_init_logger(SEXP output_directorySEXP, SEXP result_folderSEXP, SEXP algorithm_nameSEXP, SEXP algorithm_infoSEXP, SEXP datSEXP, SEXP cdatSEXP, SEXP tdatSEXP, SEXP idatSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< String >::type output_directory(output_directorySEXP);
    Rcpp::traits::input_parameter< String >::type result_folder(result_folderSEXP);
    Rcpp::traits::input_parameter< String >::type algorithm_name(algorithm_nameSEXP);
    Rcpp::traits::input_parameter< String >::type algorithm_info(algorithm_infoSEXP);
    Rcpp::traits::input_parameter< bool >::type dat(datSEXP);
    Rcpp::traits::input_parameter< bool >::type cdat(cdatSEXP);
    Rcpp::traits::input_parameter< int >::type tdat(tdatSEXP);
    Rcpp::traits::input_parameter< int >::type idat(idatSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_init_logger(output_directory, result_folder, algorithm_name, algorithm_info, dat, cdat, tdat, idat));
    return rcpp_result_gen;
END_RCPP
}
// cpp_get_problem_list
IntegerVector cpp_get_problem_list();
RcppExport SEXP _IOHexperimenter_cpp_get_problem_list() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_get_problem_list());
    return rcpp_result_gen;
END_RCPP
}
// cpp_get_dimension_list
IntegerVector cpp_get_dimension_list();
RcppExport SEXP _IOHexperimenter_cpp_get_dimension_list() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_get_dimension_list());
    return rcpp_result_gen;
END_RCPP
}
// cpp_get_instance_list
IntegerVector cpp_get_instance_list();
RcppExport SEXP _IOHexperimenter_cpp_get_instance_list() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_get_instance_list());
    return rcpp_result_gen;
END_RCPP
}
// cpp_get_suite_info
List cpp_get_suite_info();
RcppExport SEXP _IOHexperimenter_cpp_get_suite_info() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_get_suite_info());
    return rcpp_result_gen;
END_RCPP
}
// cpp_get_problem_info
List cpp_get_problem_info();
RcppExport SEXP _IOHexperimenter_cpp_get_problem_info() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_get_problem_info());
    return rcpp_result_gen;
END_RCPP
}
// cpp_get_next_problem
List cpp_get_next_problem();
RcppExport SEXP _IOHexperimenter_cpp_get_next_problem() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_get_next_problem());
    return rcpp_result_gen;
END_RCPP
}
// cpp_reset_problem
List cpp_reset_problem();
RcppExport SEXP _IOHexperimenter_cpp_reset_problem() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_reset_problem());
    return rcpp_result_gen;
END_RCPP
}
// cpp_int_evaluate
double cpp_int_evaluate(const std::vector<int>& x);
RcppExport SEXP _IOHexperimenter_cpp_int_evaluate(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<int>& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_int_evaluate(x));
    return rcpp_result_gen;
END_RCPP
}
// cpp_double_evaluate
double cpp_double_evaluate(const std::vector<double>& x);
RcppExport SEXP _IOHexperimenter_cpp_double_evaluate(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<double>& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_double_evaluate(x));
    return rcpp_result_gen;
END_RCPP
}
// cpp_loggerCOCOInfo
NumericVector cpp_loggerCOCOInfo();
RcppExport SEXP _IOHexperimenter_cpp_loggerCOCOInfo() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_loggerCOCOInfo());
    return rcpp_result_gen;
END_RCPP
}
// cpp_loggerInfo
NumericVector cpp_loggerInfo();
RcppExport SEXP _IOHexperimenter_cpp_loggerInfo() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_loggerInfo());
    return rcpp_result_gen;
END_RCPP
}
// cpp_write_line
int cpp_write_line(const std::vector<double>& line_info);
RcppExport SEXP _IOHexperimenter_cpp_write_line(SEXP line_infoSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<double>& >::type line_info(line_infoSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_write_line(line_info));
    return rcpp_result_gen;
END_RCPP
}
// cpp_logger_target_suite
int cpp_logger_target_suite();
RcppExport SEXP _IOHexperimenter_cpp_logger_target_suite() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_logger_target_suite());
    return rcpp_result_gen;
END_RCPP
}
// cpp_set_parameters_name
int cpp_set_parameters_name(const std::vector<std::string>& parameters_name);
RcppExport SEXP _IOHexperimenter_cpp_set_parameters_name(SEXP parameters_nameSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type parameters_name(parameters_nameSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_set_parameters_name(parameters_name));
    return rcpp_result_gen;
END_RCPP
}
// cpp_set_parameters_value
int cpp_set_parameters_value(const std::vector<double>& parameters);
RcppExport SEXP _IOHexperimenter_cpp_set_parameters_value(SEXP parametersSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<double>& >::type parameters(parametersSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_set_parameters_value(parameters));
    return rcpp_result_gen;
END_RCPP
}
// cpp_is_target_hit
bool cpp_is_target_hit();
RcppExport SEXP _IOHexperimenter_cpp_is_target_hit() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_is_target_hit());
    return rcpp_result_gen;
END_RCPP
}
// cpp_get_evaluations
int cpp_get_evaluations();
RcppExport SEXP _IOHexperimenter_cpp_get_evaluations() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_get_evaluations());
    return rcpp_result_gen;
END_RCPP
}
// cpp_get_optimal
double cpp_get_optimal();
RcppExport SEXP _IOHexperimenter_cpp_get_optimal() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_get_optimal());
    return rcpp_result_gen;
END_RCPP
}
// cpp_get_double_upper_bounds
NumericVector cpp_get_double_upper_bounds();
RcppExport SEXP _IOHexperimenter_cpp_get_double_upper_bounds() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_get_double_upper_bounds());
    return rcpp_result_gen;
END_RCPP
}
// cpp_get_double_lower_bounds
NumericVector cpp_get_double_lower_bounds();
RcppExport SEXP _IOHexperimenter_cpp_get_double_lower_bounds() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_get_double_lower_bounds());
    return rcpp_result_gen;
END_RCPP
}
// cpp_get_int_upper_bounds
IntegerVector cpp_get_int_upper_bounds();
RcppExport SEXP _IOHexperimenter_cpp_get_int_upper_bounds() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_get_int_upper_bounds());
    return rcpp_result_gen;
END_RCPP
}
// cpp_get_int_lower_bounds
IntegerVector cpp_get_int_lower_bounds();
RcppExport SEXP _IOHexperimenter_cpp_get_int_lower_bounds() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_get_int_lower_bounds());
    return rcpp_result_gen;
END_RCPP
}
// cpp_get_optimization_type
int cpp_get_optimization_type();
RcppExport SEXP _IOHexperimenter_cpp_get_optimization_type() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(cpp_get_optimization_type());
    return rcpp_result_gen;
END_RCPP
}
// cpp_clear_problem
void cpp_clear_problem();
RcppExport SEXP _IOHexperimenter_cpp_clear_problem() {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    cpp_clear_problem();
    return R_NilValue;
END_RCPP
}
// cpp_clear_suite
void cpp_clear_suite();
RcppExport SEXP _IOHexperimenter_cpp_clear_suite() {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    cpp_clear_suite();
    return R_NilValue;
END_RCPP
}
// cpp_clear_logger
void cpp_clear_logger();
RcppExport SEXP _IOHexperimenter_cpp_clear_logger() {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    cpp_clear_logger();
    return R_NilValue;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_IOHexperimenter_cpp_init_suite", (DL_FUNC) &_IOHexperimenter_cpp_init_suite, 4},
    {"_IOHexperimenter_cpp_init_logger", (DL_FUNC) &_IOHexperimenter_cpp_init_logger, 8},
    {"_IOHexperimenter_cpp_get_problem_list", (DL_FUNC) &_IOHexperimenter_cpp_get_problem_list, 0},
    {"_IOHexperimenter_cpp_get_dimension_list", (DL_FUNC) &_IOHexperimenter_cpp_get_dimension_list, 0},
    {"_IOHexperimenter_cpp_get_instance_list", (DL_FUNC) &_IOHexperimenter_cpp_get_instance_list, 0},
    {"_IOHexperimenter_cpp_get_suite_info", (DL_FUNC) &_IOHexperimenter_cpp_get_suite_info, 0},
    {"_IOHexperimenter_cpp_get_problem_info", (DL_FUNC) &_IOHexperimenter_cpp_get_problem_info, 0},
    {"_IOHexperimenter_cpp_get_next_problem", (DL_FUNC) &_IOHexperimenter_cpp_get_next_problem, 0},
    {"_IOHexperimenter_cpp_reset_problem", (DL_FUNC) &_IOHexperimenter_cpp_reset_problem, 0},
    {"_IOHexperimenter_cpp_int_evaluate", (DL_FUNC) &_IOHexperimenter_cpp_int_evaluate, 1},
    {"_IOHexperimenter_cpp_double_evaluate", (DL_FUNC) &_IOHexperimenter_cpp_double_evaluate, 1},
    {"_IOHexperimenter_cpp_loggerCOCOInfo", (DL_FUNC) &_IOHexperimenter_cpp_loggerCOCOInfo, 0},
    {"_IOHexperimenter_cpp_loggerInfo", (DL_FUNC) &_IOHexperimenter_cpp_loggerInfo, 0},
    {"_IOHexperimenter_cpp_write_line", (DL_FUNC) &_IOHexperimenter_cpp_write_line, 1},
    {"_IOHexperimenter_cpp_logger_target_suite", (DL_FUNC) &_IOHexperimenter_cpp_logger_target_suite, 0},
    {"_IOHexperimenter_cpp_set_parameters_name", (DL_FUNC) &_IOHexperimenter_cpp_set_parameters_name, 1},
    {"_IOHexperimenter_cpp_set_parameters_value", (DL_FUNC) &_IOHexperimenter_cpp_set_parameters_value, 1},
    {"_IOHexperimenter_cpp_is_target_hit", (DL_FUNC) &_IOHexperimenter_cpp_is_target_hit, 0},
    {"_IOHexperimenter_cpp_get_evaluations", (DL_FUNC) &_IOHexperimenter_cpp_get_evaluations, 0},
    {"_IOHexperimenter_cpp_get_optimal", (DL_FUNC) &_IOHexperimenter_cpp_get_optimal, 0},
    {"_IOHexperimenter_cpp_get_double_upper_bounds", (DL_FUNC) &_IOHexperimenter_cpp_get_double_upper_bounds, 0},
    {"_IOHexperimenter_cpp_get_double_lower_bounds", (DL_FUNC) &_IOHexperimenter_cpp_get_double_lower_bounds, 0},
    {"_IOHexperimenter_cpp_get_int_upper_bounds", (DL_FUNC) &_IOHexperimenter_cpp_get_int_upper_bounds, 0},
    {"_IOHexperimenter_cpp_get_int_lower_bounds", (DL_FUNC) &_IOHexperimenter_cpp_get_int_lower_bounds, 0},
    {"_IOHexperimenter_cpp_get_optimization_type", (DL_FUNC) &_IOHexperimenter_cpp_get_optimization_type, 0},
    {"_IOHexperimenter_cpp_clear_problem", (DL_FUNC) &_IOHexperimenter_cpp_clear_problem, 0},
    {"_IOHexperimenter_cpp_clear_suite", (DL_FUNC) &_IOHexperimenter_cpp_clear_suite, 0},
    {"_IOHexperimenter_cpp_clear_logger", (DL_FUNC) &_IOHexperimenter_cpp_clear_logger, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_IOHexperimenter(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
