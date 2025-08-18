# Problem Set

1) Count all possible ways from top left to bottom right.
2) Path with minimum Effort(leetcode dijshiktra on 2D grid)
3) Count sorted vowel strings
4) Minimum moves to reach a target score
5) Reach Nth stair
6) Nth stair with atmost K steps 
7) Reach a given score (GFG)
8) Minimum path sum (DP + dijkstra)
9) Maximum path sum in matrix (GFG - DP + Dijkstra)
10) Maximum sum Problem(https://practice.geeksforgeeks.org/problems/maximum-sum-problem2211/1#)
11) Find minimum/maximum cost of the path from any cell in the first row to any cell in the last row.
12) Longest increasing subsequence (NlogN , DP )
13) Longest arithmetic subsequence of given difference
14) Longest arithmetic subsequence (extension of above problem)
15) Number of longest increasing subsequence
16) Longest Bitonic Subsequence 
17) Longest sum Bitonic Subsequence 
18) Maximum sum subarray 
19) Kadanes Algorithm(Maximum sum subarray)
20) Maximum Absolute Sum of Any Subarray
21) Skip the work(direct dp solution and converting the recursive program into dp) 
22) Yet another broken keyboard-codeforces
23) Caesar's Legions codeforces
24) Flower eating marmot 
25) Optimal game strategy (GFG)
26) Predict the winner
27) Maximum earnings from Taxi
28) Pots of gold game 
29) Maximum Tip Calculator 
30) 0-1 Knapsack 
31) 0-1 knapsack unbounded
32) Dice Combinations(CSES)
33) Coin Combinations-1(CSES - Permutations taken into account. 1D problem with outer loop running on the sum)
34) Coin Combinations-2(CSES - only Combinations are taken into account.1D problem with inner loop running on the sum)
35) Refer permutations_and_combinations readme file
36) Coin change (Miminum coins to make target)
37) Minimizing coins(CSES)
38) Coin change - II (using each element any no. of times, find the no. of combinations of elements which add up to form a given target)
39) Length of longest subsequence that sums to target
40) Inverse coin change
41) Number of ways to select buildings
42) -
43) Perfect sum problem - No. of subsets with given sum(Inner loop running on sum. Understand why ?? 2D similar to 0-1 knapsack)
44) Perfect sum problem - No. of subsets with given sum(1D with inner loop running on sum but reversed)
45) Partial Equal Subset sum(1D problem correlate with above problems)
46) Count Ways to reach Nth stair
47) Minimum No. of coins to make a change.
48) Maximize the cut segments
49) Number of ways to earn points
50) Rod cutting Problem(maximum profit problem)
51) Minimum cost to cut a stick (leetcode - missed out problem must do, https://leetcode.com/problems/minimum-cost-to-cut-a-stick/solutions/780880/dp-with-picture-burst-balloons/)
52) Burst balloons (leetcode - https://leetcode.com/problems/burst-balloons/solutions/892552/for-those-who-are-not-able-to-understand-sq5m/)
53) Consecutive 1's not allowed 
54) House robber - 1 (recursion + DP leetcode)
38) House robber - 2 (recursion + DP leetcode)
38) Count possible ways to construct Buildings
39) Longest Path in Directed Acyclic graph
40) Buy and sell stocks(one transaction allowed) - I  
41) Buy and sell stocks(multiple transactions) - II (refer recursive and iterative and analyse why dp cannot be used in this problem) 
43) Buy and sell stocks(multiple transactions) with cooldown 
44) Buy and sell stocks(multiple transactions) with transaction fee
45) Buy and sell stocks(atmost 2 transactions) 
46) Buy and sell stocks(atmost k transactions)
47) 2 keys keyboard (recursion + DP)
48) Edit distance (recursion + DP) 
49) Minimum White Tiles After Covering With Carpets (recursion + DP leetcode)
50) Delete Operation for Two Strings (recursion + DP)
51) Minimum ascii delete sum to make 2 strings same (recursion + DP)
52) Partition equal subset sum (leetcode , recursion + DP) 
53) Word break I
54) Word break II (no dp involved only recursion and backtracking)
55) Wildcard matching
53) Partition with k equal subset sum (leetcode , Can be done only with backtracking)
54) Given an array of size N in how many ways you can get a sum of k using elements of the array.
55) Partition Array Into Two Arrays to Minimize Sum Difference
56) No repetition + Combinations 
57) No repetition + Permutations 
58) Repetition + Combinations ( CSES coin Combination - 2 )
59) Repetition + Permutations ( CSES Coin Combination - 1 )
60) Combination sum - 1 (leetcode)
61) Combination sum - 2 (leetcode very important)
62) Combination sum - 3 (leetcode) 
63) Combination sum - 4 (leetcode - VERY VERY IMPORTANT. compare with perfect sum problem of GFG) 
64) Palindrome partitioning - 1 (backtracking , leetcode) 
65) Palindrome partitioning - 2 ( DP , leetcode )
66) Palindrome partitioning - 3 ( DP , leetcode )
67) Palindrome partitioning - 4 ( DP , leetcode )
68) Maximum Value of K Coins From Piles (leetcode)
69) Jump Game - 1 (leetcode)
70) Jump Game - 2 (leetcode can be done using BFS and also DP)
71) Jump Game - 3 (leetcode-BFS)
72) Jump Game - 4 (leetcode-BFS)
73) Maximum numbers of jumps to reach the last index
74) Frog jump
75) Extra characters in a string
76) cherry pickup II
77) Partitions with given difference (try writing iterative solution)
78) Partition to K equal sum subsets (backtracking)
79) Partition array for maximum sum
80) Number of Increasing Paths in a Grid (very very important + backtracking)


# Combinations and Permutations counting problems
Given an input array and a target value , the possible type of problems that we face are listed below.
      Array              restriction       output 
1) distinct elements + taken only once + Combinations ( combination sum - 3 )
2) Distinct elements + taken any times + Combinations ( coin combinations - 2 , combination sum - 1 )
3) Distinct elements + taken only once + Permutations  
4) Distinct elements + taken any times + Permutations ( combination sum - 4 , coin combinations - 1 )
5) Repetition of elements + taken only once + Combinations ( combination sum - 2 )
6) Repetition of elements + taken any times + Combinations 
7) Repetition of elements + taken only once + Permutations
8) Repetition of elements + taken any times + Permutations

# strings 
1) Longest common subsequence (from recursive dp to tabulation to space optimisation)
2) Print longest common subsequence
3) Maximum length of repeated subarray (same as longest common substring)
4) Edit distance
5) Longest palindromic subsequence (find LCS between string and its reverse - This does not work for longest palindromic substring)
6) Longest palindromine substring (solved by DP but can be solved manacher's algorithm)
7) Palindromic substrings
8) Minimum insertion steps to make a string palindrome (length of string - length of longest palindromic subsequence)
9) Shortest common supersequence (len(s1) - LCS(s1,s2) + len(s2) - LCS(s1,s2) - LCS(s1,s2))

# Missed out problems
1) Increasing triplet subsequence
2) Longest increasing subsequence II
3) Longest subsequence with decreasing adjacent difference
4) Find the maximum length of valid subsequence I
5) Find the maximum length of valid subsequence II
6) Inverse coin change
7) Count of subsets with sum equal to target (Can this be done in 1D DP ? Compare the solutions with both coin combinations-1,2)
8) Two Best Non-Overlapping Events
9) Egg dropping problem


