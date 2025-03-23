#pragma once

#include <vector>
#include <algorithm>

namespace alg
{
	namespace sig
	{

		template<typename T>
		class Data
		{
		private:
			std::vector<T> Samples;
		public:
			Data() {}
			Data(size_t N){ Samples.resize(N); }
			auto begin()
			{
				return Samples.begin();
			}

			auto end()
			{
				return Samples.end();
			}

			auto resize(const size_t& N)
			{
				Samples.resize(N);
			}

			auto size() const
			{
				return Samples.size();
			}

			std::vector<T>& getBuff()
			{
				return Samples;
			}
		};
	}
}
