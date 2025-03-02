#ifndef BMI_H
#define BMI_H

// 通过指针传递结果（避免值拷贝）
void calculator_bmi(float *height, float *weight, float *result);

// 输出健康建议
void print_bmi_advice(float bmi);

#endif