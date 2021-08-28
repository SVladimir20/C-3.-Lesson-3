#include <iostream>
#include <vector>
using namespace std;

class Range
{
private:
	class Impl
	{
	public:
		Impl(const size_t v, const vector<int> &values) : i_idx(v), i_values(values) {}
		auto operator*() const { return i_values[i_idx]; }
		auto &operator++()
		{
			i_idx++;
			return *this;
		}
		bool operator!=(const Impl &rhs) const { return i_idx != rhs.i_idx; }

	private:
		size_t i_idx;
		const vector<int> &i_values;
	};

public:
	Range(const vector<int> &values) : r_values(values) {}
	typedef Impl iterator;
	iterator begin() const { return Impl(0, r_values); }
	iterator end() const { return Impl(r_values.size(), r_values); }

private:
	const vector<int> &r_values;
};

int main()
{
	const vector<int> integer = { 1, 2, 3, 4, 5, 6 };
	for (const int &i : Range(integer))
	{
		cout << i << endl;
	}
	return 0;
}