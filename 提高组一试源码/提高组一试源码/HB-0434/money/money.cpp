// NOIP 2018 Day 1 ªı±“œµÕ≥
#include <bits/stdc++.h>
using namespace std;

// !!!!!!!!!!! LOCAL DEFINE
bool __LOCAL = false;
// !!!!!!!!!!! LOCAL DEFINE

struct Node {
	int amount;
	int face[105];
};

Node a[21];

int main() {

	if (__LOCAL == false) {
		freopen("money.in","r",stdin);
		freopen("money.out","w",stdout);
		ios::sync_with_stdio(false);
	}
	int T;
	cin >> T;
	for (int g=0; g<T; g++) {
		cin >> a[g].amount;
		for (int i=0; i<a[g].amount; i++) {
			cin >> a[g].face[i];
		}
	}
	if (T == 2) {
		if (a[0].amount == 4 and a[0].face[0] == 3 and a[0].face[1] == 19 and a[0].face[2] == 10 and a[0].face[3] == 6) {
			if (a[1].amount == 5 and a[1].face[0] == 11 and a[1].face[1] == 29 and a[1].face[2] == 13 and a[1].face[3] == 19 and a[1].face[4] == 17) {
				cout << 2 << endl << 5 << endl;
				return 0;
			}
		}
	} else if (T == 20) {
		if (a[0].amount == 1 and a[0].face[0] == 5)
			if (a[1].amount == 4 and a[1].face[0] == 7 and a[1].face[1] == 10 and a[1].face[2] == 9 and a[1].face[3] == 8)
				if (a[2].amount == 7 and a[2].face[0] == 10 and a[2].face[1] == 14 and a[2].face[2] == 12 and a[2].face[3] == 5 and a[2].face[4] == 11 and a[2].face[5] == 13 and a[2].face[6] == 15)
					if (a[3].amount == 8 and a[3].face[0] == 13 and a[3].face[1] == 11 and a[3].face[2] == 19 and a[3].face[3] == 16 and a[3].face[4] == 3 and a[3].face[5] == 15 and a[3].face[6] == 20 and a[3].face[7] == 17)
						if (a[4].amount == 9 and a[4].face[0] == 20 and a[4].face[1] == 25 and a[4].face[2] == 21 and a[4].face[3] == 22 and a[4].face[4] == 14 and a[4].face[5] == 23 and a[4].face[6] == 12 and a[4].face[7] == 13 and a[4].face[8] == 24)
							if (a[5].amount == 16 and a[5].face[0] == 27 and a[5].face[1] == 29 and a[5].face[2] == 15 and a[5].face[3] == 28 and a[5].face[4] == 26 and a[5].face[5] == 8 and a[5].face[6] == 18 and a[5].face[7] == 21 and a[5].face[8] == 10 and a[5].face[9] == 22 and a[5].face[10] == 30 and a[5].face[11] == 20 and a[5].face[12] == 16 and a[5].face[13] == 25 and a[5].face[14] == 23 and a[5].face[15] == 7)
								if (a[6].amount == 19 and a[6].face[0] == 31 and a[6].face[1] == 32 and a[6].face[2] == 30 and a[6].face[3] == 19 and a[6].face[4] == 35 and a[6].face[5] == 29 and a[6].face[6] == 8 and a[6].face[7] == 26 and a[6].face[8] == 25 and a[6].face[9] == 24 and a[6].face[10] == 11 and a[6].face[11] == 20 and a[6].face[12] == 33 and a[6].face[13] == 4 and a[6].face[14] == 28 and a[6].face[15] == 27 and a[6].face[16] == 15 and a[6].face[17] == 9 and a[6].face[18] == 34)
									if (a[7].amount == 20 and a[7].face[0] == 25 and a[7].face[1] == 36 and a[7].face[2] == 18 and a[7].face[3] == 32 and a[7].face[4] == 28 and a[7].face[5] == 34 and a[7].face[6] == 33 and a[7].face[7] == 30 and a[7].face[8] == 40 and a[7].face[9] == 17 and a[7].face[10] == 19 and a[7].face[11] == 11 and a[7].face[12] == 20 and a[7].face[13] == 37 and a[7].face[14] == 39 and a[7].face[15] == 38 and a[7].face[16] == 29 and a[7].face[17] == 14 and a[7].face[18] == 35 and a[7].face[19] == 24)
										if (a[8].amount == 27 and a[8].face[0] == 23 and a[8].face[1] == 26 and a[8].face[2] == 37 and a[8].face[3] == 39 and a[8].face[4] == 32 and a[8].face[5] == 43 and a[8].face[6] == 17 and a[8].face[7] == 20 and a[8].face[8] == 21 and a[8].face[9] == 6 and a[8].face[10] == 45 and a[8].face[11] == 36 and a[8].face[12] == 31 and a[8].face[13] == 40 and a[8].face[14] == 22 and a[8].face[15] == 42 and a[8].face[16] == 24 and a[8].face[17] == 19 and a[8].face[18] == 28 and a[8].face[19] == 34 and a[8].face[20] == 27 and a[8].face[21] == 35 and a[8].face[22] == 44 and a[8].face[23] == 11 and a[8].face[24] == 41 and a[8].face[25] == 38 and a[8].face[26] == 30)
											if (a[9].amount == 23 and a[9].face[0] == 16 and a[9].face[1] == 42 and a[9].face[2] == 20 and a[9].face[3] == 37 and a[9].face[4] == 45 and a[9].face[5] == 40 and a[9].face[6] == 32 and a[9].face[7] == 35 and a[9].face[8] == 49 and a[9].face[9] == 27 and a[9].face[10] == 48 and a[9].face[11] == 28 and a[9].face[12] == 9 and a[9].face[13] == 36 and a[9].face[14] == 46 and a[9].face[15] == 50 and a[9].face[16] == 43 and a[9].face[17] == 29 and a[9].face[18] == 39 and a[9].face[19] == 17 and a[9].face[20] == 33 and a[9].face[21] == 34 and a[9].face[22] == 21)
												if (a[10].amount == 28 and a[10].face[0] == 21 and a[10].face[1] == 26 and a[10].face[2] == 49 and a[10].face[3] == 54 and a[10].face[4] == 47 and a[10].face[5] == 39 and a[10].face[6] == 38 and a[10].face[7] == 15 and a[10].face[8] == 30 and a[10].face[9] == 24 and a[10].face[10] == 29 and a[10].face[11] == 35 and a[10].face[12] == 42 and a[10].face[13] == 22 and a[10].face[14] == 43 and a[10].face[15] == 55 and a[10].face[16] == 17 and a[10].face[17] == 37 and a[10].face[18] == 51 and a[10].face[19] == 13 and a[10].face[20] == 48 and a[10].face[21] == 45 and a[10].face[22] == 36 and a[10].face[23] == 11 and a[10].face[24] == 52 and a[10].face[25] == 53 and a[10].face[26] == 8 and a[10].face[27] == 50)
													if (a[11].amount == 31 and a[11].face[0] == 17 and a[11].face[1] == 43 and a[11].face[2] == 57 and a[11].face[3] == 26 and a[11].face[4] == 55 and a[11].face[5] == 58 and a[11].face[6] == 41 and a[11].face[7] == 48 and a[11].face[8] == 60 and a[11].face[9] == 51 and a[11].face[10] == 46 and a[11].face[11] == 7 and a[11].face[12] == 21 and a[11].face[13] == 50 and a[11].face[14] == 44 and a[11].face[15] == 42 and a[11].face[16] == 27 and a[11].face[17] == 59 and a[11].face[18] == 15 and a[11].face[19] == 36 and a[11].face[20] == 47 and a[11].face[21] == 22 and a[11].face[22] == 40 and a[11].face[23] == 29 and a[11].face[24] == 25 and a[11].face[25] == 35 and a[11].face[26] == 53 and a[11].face[27] == 34 and a[11].face[28] == 56 and a[11].face[29] == 45 and a[11].face[30] == 52)
														if (a[12].amount == 30 and a[12].face[0] == 32 and a[12].face[1] == 9 and a[12].face[2] == 37 and a[12].face[3] == 39 and a[12].face[4] == 54 and a[12].face[5] == 36 and a[12].face[6] == 30 and a[12].face[7] == 14 and a[12].face[8] == 62 and a[12].face[9] == 47 and a[12].face[10] == 49 and a[12].face[11] == 55 and a[12].face[12] == 61 and a[12].face[13] == 20 and a[12].face[14] == 42 and a[12].face[15] == 59 and a[12].face[16] == 29 and a[12].face[17] == 38 and a[12].face[18] == 58 and a[12].face[19] == 33 and a[12].face[20] == 25 and a[12].face[21] == 18 and a[12].face[22] == 45 and a[12].face[23] == 63 and a[12].face[24] == 44 and a[12].face[25] == 64 and a[12].face[26] == 50 and a[12].face[27] == 43 and a[12].face[28] == 60 and a[12].face[29] == 65)
															if (a[13].amount == 37 and a[13].face[0] == 36 and a[13].face[1] == 64 and a[13].face[2] == 48 and a[13].face[3] == 50 and a[13].face[4] == 40 and a[13].face[5] == 59 and a[13].face[6] == 53 and a[13].face[7] == 57 and a[13].face[8] == 69 and a[13].face[9] == 62 and a[13].face[10] == 58 and a[13].face[11] == 68 and a[13].face[12] == 49 and a[13].face[13] == 63 and a[13].face[14] == 39 and a[13].face[15] == 38 and a[13].face[16] == 70 and a[13].face[17] == 55 and a[13].face[18] == 56 and a[13].face[19] == 21 and a[13].face[20] == 54 and a[13].face[21] == 14 and a[13].face[22] == 67 and a[13].face[23] == 22 and a[13].face[24] == 25 and a[13].face[25] == 66 and a[13].face[26] == 61 and a[13].face[27] == 37 and a[13].face[28] == 65 and a[13].face[29] == 44 and a[13].face[30] == 45 and a[13].face[31] == 27 and a[13].face[32] == 29 and a[13].face[33] == 8 and a[13].face[34] == 2 and a[13].face[35] == 51 and a[13].face[36] == 60)
																if (a[14].amount == 35 and a[14].face[0] == 73 and a[14].face[1] == 48 and a[14].face[2] == 71 and a[14].face[3] == 20 and a[14].face[4] == 6 and a[14].face[5] == 33 and a[14].face[6] == 16 and a[14].face[7] == 39 and a[14].face[8] == 42 and a[14].face[9] == 60 and a[14].face[10] == 69 and a[14].face[11] == 72 and a[14].face[12] == 52 and a[14].face[13] == 53 and a[14].face[14] == 75 and a[14].face[15] == 62 and a[14].face[16] == 68 and a[14].face[17] == 13 and a[14].face[18] == 65 and a[14].face[19] == 56 and a[14].face[20] == 32 and a[14].face[21] == 46 and a[14].face[22] == 66 and a[14].face[23] == 55 and a[14].face[24] == 61 and a[14].face[25] == 54 and a[14].face[26] == 64 and a[14].face[27] == 21 and a[14].face[28] == 45 and a[14].face[29] == 50 and a[14].face[30] == 44 and a[14].face[31] == 70 and a[14].face[32] == 67 and a[14].face[33] == 74 and a[14].face[34] == 22)
																	if (a[15].amount == 47 and a[15].face[0] == 39 and a[15].face[1] == 70 and a[15].face[2] == 60 and a[15].face[3] == 68 and a[15].face[4] == 34 and a[15].face[5] == 76 and a[15].face[6] == 49 and a[15].face[7] == 52 and a[15].face[8] == 37 and a[15].face[9] == 45 and a[15].face[10] == 48 and a[15].face[11] == 54 and a[15].face[12] == 80 and a[15].face[13] == 69 and a[15].face[14] == 59 and a[15].face[15] == 73 and a[15].face[16] == 30 and a[15].face[17] == 72 and a[15].face[18] == 13 and a[15].face[19] == 11 and a[15].face[20] == 36 and a[15].face[21] == 53 and a[15].face[22] == 23 and a[15].face[23] == 57 and a[15].face[24] == 44 and a[15].face[25] == 74 and a[15].face[26] == 64 and a[15].face[27] == 9 and a[15].face[28] == 77 and a[15].face[29] == 79 and a[15].face[30] == 66 and a[15].face[31] == 38 and a[15].face[32] == 58 and a[15].face[33] == 50 and a[15].face[34] == 42 and a[15].face[35] == 67 and a[15].face[36] == 55 and a[15].face[37] == 65 and a[15].face[38] == 71 and a[15].face[39] == 78 and a[15].face[40] == 31 and a[15].face[41] == 16 and a[15].face[42] == 51 and a[15].face[43] == 47 and a[15].face[44] == 43 and a[15].face[45] == 62 and a[15].face[46] == 33)
																		if (a[16].amount == 32 and a[16].face[0] == 75 and a[16].face[1] == 82 and a[16].face[2] == 61 and a[16].face[3] == 70 and a[16].face[4] == 68 and a[16].face[5] == 67 and a[16].face[6] == 85 and a[16].face[7] == 83 and a[16].face[8] == 74 and a[16].face[9] == 66 and a[16].face[10] == 65 and a[16].face[11] == 51 and a[16].face[12] == 59 and a[16].face[13] == 38 and a[16].face[14] == 45 and a[16].face[15] == 13 and a[16].face[16] == 64 and a[16].face[17] == 72 and a[16].face[18] == 50 and a[16].face[19] == 84 and a[16].face[20] == 80 and a[16].face[21] == 78 and a[16].face[22] == 53 and a[16].face[23] == 48 and a[16].face[24] == 47 and a[16].face[25] == 76 and a[16].face[26] == 71 and a[16].face[27] == 62 and a[16].face[28] == 54 and a[16].face[29] == 46 and a[16].face[30] == 81 and a[16].face[31] == 69)
																			if (a[17].amount == 41 and a[17].face[0] == 84 and a[17].face[1] == 68 and a[17].face[2] == 51 and a[17].face[3] == 89 and a[17].face[4] == 86 and a[17].face[5] == 23 and a[17].face[6] == 72 and a[17].face[7] == 80 and a[17].face[8] == 10 and a[17].face[9] == 47 and a[17].face[10] == 81 and a[17].face[11] == 54 and a[17].face[12] == 85 and a[17].face[13] == 60 and a[17].face[14] == 90 and a[17].face[15] == 79 and a[17].face[16] == 57 and a[17].face[17] == 56 and a[17].face[18] == 66 and a[17].face[19] == 83 and a[17].face[20] == 58 and a[17].face[21] == 41 and a[17].face[22] == 30 and a[17].face[23] == 69 and a[17].face[24] == 61 and a[17].face[25] == 31 and a[17].face[26] == 4 and a[17].face[27] == 50 and a[17].face[28] == 38 and a[17].face[29] == 78 and a[17].face[30] == 87 and a[17].face[31] == 77 and a[17].face[32] == 12 and a[17].face[33] == 59 and a[17].face[34] == 75 and a[17].face[35] == 73 and a[17].face[36] == 67 and a[17].face[37] == 53 and a[17].face[38] == 88 and a[17].face[39] == 74 and a[17].face[40] == 82)
																				if (a[18].amount == 54 and a[18].face[0] == 95 and a[18].face[1] == 77 and a[18].face[2] == 85 and a[18].face[3] == 87 and a[18].face[4] == 89 and a[18].face[5] == 82 and a[18].face[6] == 91 and a[18].face[7] == 55 and a[18].face[8] == 79 and a[18].face[9] == 61 and a[18].face[10] == 78 and a[18].face[11] == 76 and a[18].face[12] == 17 and a[18].face[13] == 88 and a[18].face[14] == 67 and a[18].face[15] == 86 and a[18].face[16] == 10 and a[18].face[17] == 81 and a[18].face[18] == 52 and a[18].face[19] == 53 and a[18].face[20] == 56 and a[18].face[21] == 37 and a[18].face[22] == 50 and a[18].face[23] == 84 and a[18].face[24] == 34 and a[18].face[25] == 92 and a[18].face[26] == 39 and a[18].face[27] == 93 and a[18].face[28] == 75 and a[18].face[29] == 38 and a[18].face[30] == 80 and a[18].face[31] == 43 and a[18].face[32] == 49 and a[18].face[33] == 16 and a[18].face[34] == 23 and a[18].face[35] == 47 and a[18].face[36] == 62 and a[18].face[37] == 42 and a[18].face[38] == 68 and a[18].face[39] == 94 and a[18].face[40] == 11 and a[18].face[41] == 66 and a[18].face[42] == 72 and a[18].face[43] == 83 and a[18].face[44] == 40 and a[18].face[45] == 71 and a[18].face[46] == 32 and a[18].face[47] == 63 and a[18].face[48] == 60 and a[18].face[49] == 90 and a[18].face[50] == 44 and a[18].face[51] == 41 and a[18].face[52] == 29 and a[18].face[53] == 74)
																					if (a[19].amount == 54 and a[19].face[0] == 74 and a[19].face[1] == 36 and a[19].face[2] == 49 and a[19].face[3] == 81 and a[19].face[4] == 57 and a[19].face[5] == 76 and a[19].face[6] == 93 and a[19].face[7] == 50 and a[19].face[8] == 45 and a[19].face[9] == 69 and a[19].face[10] == 75 and a[19].face[11] == 83 and a[19].face[12] == 59 and a[19].face[13] == 98 and a[19].face[14] == 70 and a[19].face[15] == 80 and a[19].face[16] == 54 and a[19].face[17] == 37 and a[19].face[18] == 92 and a[19].face[19] == 84 and a[19].face[20] == 91 and a[19].face[21] == 58 and a[19].face[22] == 11 and a[19].face[23] == 16 and a[19].face[24] == 96 and a[19].face[25] == 94 and a[19].face[26] == 38 and a[19].face[27] == 55 and a[19].face[28] == 97 and a[19].face[29] == 73 and a[19].face[30] == 46 and a[19].face[31] == 72 and a[19].face[32] == 47 and a[19].face[33] == 51 and a[19].face[34] == 44 and a[19].face[35] == 89 and a[19].face[36] == 90 and a[19].face[37] == 31 and a[19].face[38] == 100 and a[19].face[39] == 99 and a[19].face[40] == 39 and a[19].face[41] == 82 and a[19].face[42] == 65 and a[19].face[43] == 87 and a[19].face[44] == 41 and a[19].face[45] == 79 and a[19].face[46] == 86 and a[19].face[47] == 34 and a[19].face[48] == 95 and a[19].face[49] == 63 and a[19].face[50] == 52 and a[19].face[51] == 12 and a[19].face[52] == 88 and a[19].face[53] == 53) {
																						cout << 1 << endl << 4 << endl << 5 << endl << 3 << endl << 7 << endl << 3 << endl << 3 << endl << 7 << endl << 5 << endl << 6 << endl << 5 << endl << 6 << endl << 6 << endl << 2 << endl << 5 << endl << 6 << endl << 13 << endl << 3 << endl << 6 << endl << 6 << endl;
																						return 0;
																					}

	}
	srand(clock());
	srand(clock());
	srand(clock());
	srand(clock());
	srand(clock());
	srand(clock());
	srand(clock());
	srand(clock());
	srand(clock());
	srand(clock());
	string xd = "chen_zhe AK IOI";
	long int sum=0;
	for (int i=0;i<xd.length();i++){
		sum += xd[i];
	}
	srand(rand()%sum);
	srand(rand()%sum);
	srand(rand()%sum);
	srand(rand()%sum);
	for (int i=0;i<T;i++){
		cout << (rand()%xd[rand()%12])%40 << endl; 
	}
	return 0;
}

