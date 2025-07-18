#include <bits/stdc++.h>

using namespace std;

#include <stdio.h>
#include <ctype.h>

class InParser {
private:
	FILE *fin;
	char *buff;
	int sp;

	char read_ch() {
		++sp;
		if (sp == 4096) {
			sp = 0;
			fread(buff, 1, 4096, fin);
		}
		return buff[sp];
	}

public:
	InParser(const char* nume) {
		fin = fopen(nume, "r");
		buff = new char[4096]();
		sp = 4095;
	}
	
	InParser& operator >> (int &n) {
		char c;
		while (!isdigit(c = read_ch()) && c != '-');
		int sgn = 1;
		if (c == '-') {
			n = 0;
			sgn = -1;
		} else {
			n = c - '0';
		}
		while (isdigit(c = read_ch())) {
			n = 10 * n + c - '0';
		}
		n *= sgn;
		return *this;
	}
	
	InParser& operator >> (long long &n) {
		char c;
		n = 0;
		while (!isdigit(c = read_ch()) && c != '-');
		long long sgn = 1;
		if (c == '-') {
			n = 0;
			sgn = -1;
		} else {
			n = c - '0';
		}
		while (isdigit(c = read_ch())) {
			n = 10 * n + c - '0';
		}
		n *= sgn;
		return *this;
	}
};

InParser fin ("episodul1.in");

#include <cstdio>
#include <cstring>

using namespace std;

class OutParser {
private:
    FILE *fout;
    char *buff;
    int sp;
 
    void write_ch(char ch) {
        if (sp == 50000) {
            fwrite(buff, 1, 50000, fout);
            sp = 0;
            buff[sp++] = ch;
        } else {
            buff[sp++] = ch;
        }
    }
 
 
public:
    OutParser(const char* name) {
        fout = fopen(name, "w");
        buff = new char[50000]();
        sp = 0;
    }
    ~OutParser() {
        fwrite(buff, 1, sp, fout);
        fclose(fout);
    }
 
    OutParser& operator << (int vu32) {
        if (vu32 <= 9) {
            write_ch(vu32 + '0');
        } else {
            (*this) << (vu32 / 10);
            write_ch(vu32 % 10 + '0');
        }
        return *this;
    }
 
    OutParser& operator << (long long vu64) {
        if (vu64 <= 9) {
            write_ch(vu64 + '0');
        } else {
            (*this) << (vu64 / 10);
            write_ch(vu64 % 10 + '0');
        }
        return *this;
    }
 
    OutParser& operator << (char ch) {
        write_ch(ch);
        return *this;
    }
    OutParser& operator << (const char *ch) {
        while (*ch) {
            write_ch(*ch);
            ++ch;
        }
        return *this;
    }
};

OutParser fout("episodul1.out");

struct DSU
{
    vector<int> T;
    vector<int> size;
    long long int cost[1000009];

    DSU(int N)
    {
        T.resize(N + 1);
        size.resize(N + 1);
        iota(T.begin(), T.end(), 0);
    }

    int find(int a)
    {
        if(a == T[a])
            return a;
        return T[a] = find(T[a]);
    }

    long long int findCost(int a)
    {
        int radacina = find(a);
        return cost[radacina];
    }

    void join(int a, int b, int c)
    {
        a = find(a);
        b = find(b);

        if(size[a] > size[b])
            swap(a,  b);
        cost[a] += cost[b] + c;
        cost[b] = cost[a];
        size[b] += size[a];
        T[a] = b;
    }

    bool query(int a, int b)
    {
        a = find(a);
        b = find(b);

        return a == b;
    }
};

struct Edge
{
    int x, y, cost;
};

int main()
{
    int n;
    fin >> n;
    DSU dsu(1000009);
    for(int i = 1; i <= n; i++)
    {
        int op;
        fin >> op;
        if(op == 1);
        else if(op == 2)
        {
            int x, y, c;
            fin >> x >> y >> c;
            if(dsu.find(x) != dsu.find(y))
                dsu.join(x, y, c);
        }
        else
        {
            int x;
            fin >> x;
            fout << dsu.findCost(x) << '\n';
        }
    }
    

    return 0;
}