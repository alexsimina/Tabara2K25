
#include <bits/stdc++.h>

using namespace std;

mt19937 get_rng() {
	seed_seq seq {
		(uint64_t) chrono::duration_cast<chrono::nanoseconds>(
			chrono::high_resolution_clock::now().time_since_epoch()).count(),
		(uint64_t) __builtin_ia32_rdtsc(),
		(uint64_t) (uintptr_t) unique_ptr<char>(new char).get()
	};
	return mt19937(seq);
}

auto rng = get_rng();

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    int max_len = atoi(argv[2]);

    cout << "2 " << N << '\n';
	uniform_int_distribution<int> gen_len(1, max_len);
	uniform_int_distribution<int> gen_char(0, 25);
	for(int i = 1; i <= N; i++)
	{
		int len = gen_len(rng);
		for(int j = 1; j <= len; j++)
		{
			char c = 'a' + gen_char(rng);
			cout << c;
		}
		cout << '\n';
	}
    return 0;
}