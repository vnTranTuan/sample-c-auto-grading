#include <stdio.h>
#include <stdlib.h>
#include "CUnit.h"
#include "Basic.h"
#include "my_functions.h"

void test_Tinh_Tong() {
    // Test với các số nguyên
    CU_ASSERT_EQUAL(Tinh_Tong(2, 3), 5);
    CU_ASSERT_EQUAL(Tinh_Tong(0, 0), 0);
    CU_ASSERT_EQUAL(Tinh_Tong(-1, 1), 0);
    CU_ASSERT_EQUAL(Tinh_Tong(-2, -3), -5);

    // Test với số thực 
    // sẽ bị lỗi vì hàm Tinh_Tong nhận int
    CU_ASSERT_EQUAL(Tinh_Tong(1.5, 2.5), 4);
}

// Hàm khởi tạo và dọn dẹp test suite
int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

// Hàm chính để chạy unit test
int main() {
    CU_pSuite pSuite = NULL;

    // Khởi tạo hệ thống kiểm thử
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Thêm test suite vào registry
    pSuite = CU_add_suite(
        "My_Functions_Test_Suite", 
        init_suite, clean_suite);

    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Thêm các test case vào test suite
    if (NULL == CU_add_test(
                    pSuite, 
                    "Tinh_Tong Test 1", 
                    test_Tinh_Tong)){    
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Chạy các test case bằng giao diện Basic
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();

}