#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m, k;
		cin >> n >> m >> k;
		// n / k = x cards per player
		// m <= x, m jokers
		// m > x, x jokers on 1st player
		
		// n = 9 cards, k = 3 players
		// x = n / k = 9 / 3 = 3 cards per player
		// 6 <= 3, false
		// 6 > 3, 3 jokers on 1st player, 2 players left
		// 6 - 3 = 3 jokers left
		// 2 jokers on the 2nd player, 1 joker on the 3rd player
		// answer = 3 - 2 = 1 point

		// n = 8 cards, k = 4 players
		// x = n / k = 8 / 4 = 2 cards per player
		// 6 <= 2, false
		// 6 > 2, 2 jokers on the 1st player, 3 players left
		// 6 - 2 = 4 jokers left
		// ceil(4 / 3) = 2 jokers on one of the remaining players, the rest would get 1
		// answer = 2 - 2 = 0

		// n = 8 cards, k = 2 players
		// x = n / k = 8 / 2 = 4 cards per player
		// 3 <= 4, 3 jokers on the 1st player, 1 player left
		// 3 - 3 = 0 jokers left
		// answer = 3 - 0 = 0

		// n = 4 cards, k = 4 players
		// x = n / k = 4 / 4 = 1 cards per player
		// 2 <= 1, false
		// 2 > 1, 1 joker on the 1st player, 3 players left
		// 2 - 1 = 1 joker left
		// ceil(1 / 3) = 1 joker on the remaining player, the rest would get 0
		// answer = 1 - 1 = 0
		
		int ans = 0;
		int cards_per_player = n / k;
		if (m <= cards_per_player) {
			ans = m;
		} else {
			int remaining = m - cards_per_player;
			int other_jokers = (remaining % (k - 1) == 0 ? remaining / (k - 1) : remaining / (k - 1) + 1);
			ans = cards_per_player - other_jokers;
		}
		cout << ans << '\n';
	}
	return 0;
}