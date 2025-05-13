#pragma once

#ifndef GALE_SHAPLEY
#define GALE_SHAPLEY

#include "common.hpp"

/**
 * Implements the Gale-Shapley algorithm for stable matching between two sets.
 *
 * This function computes a stable matching between two sets A (of size n) and B (of size m),
 * where each element in A has preferences over elements in B (PA) and vice versa (PB).
 * The matching produced is A-optimal, meaning it's optimal for all elements in A
 * among all possible stable matchings.
 *
 * @param PA Preference list for elements in A. PA[a] is an ordered list where PA[a][0]
 *           is the most preferred element of B for element a in A.
 * @param PB Preference list for elements in B. PB[b] is an ordered list where PB[b][0]
 *           is the most preferred element of A for element b in B.
 * @return   A vector where the a-th entry contains the index of the matched element in B
 *           for element a in A (-1 if unmatched).
 *
 * @note The matching will always be perfect if n ≤ m (all elements in A will be matched)
 * @note Time complexity: O(n*m) in worst case
 * @note Space complexity: O(n*m) for storing preference indices
 *
 * Example usage:
 * @code
 *   intmatrix PA = {{1, 0}, {0, 1}};  // Preferences for A elements
 *   intmatrix PB = {{0, 1}, {1, 0}};  // Preferences for B elements
 *   vector<int> matching = gale_shapley(PA, PB);
 *   // matching[0] will be 1 (A0 matched with B1)
 *   // matching[1] will be 0 (A1 matched with B0)
 * @endcode
 */
void gale_shapley(int n, std::vector<int> &h2s, std::vector<int> &s2h, intmatrix &hp, intmatrix &sp);

#endif //GALE_SHAPLEY