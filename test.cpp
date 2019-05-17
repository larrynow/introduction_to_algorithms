#include"longest_common_subsequence_test.h"
#include"bottom_up_rod_cutting_test.h"
#include"matrix_chain_order_test.h"
#include"optimal_bst_test.h"
#include"sign_player_test.h"
#include"bitonic_tour_test.h"
#include"activity_selector_test.h"
#include"huffman_test.h"
#include"matroid_task_scheduling_test.h"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}