#pragma once

#include "Channel.h"

#include <string>

#include <unordered_map>
#include <iostream>
namespace cm
{
	namespace ch
	{
		constexpr const int numCh = 9;
		using ChannelTuple = std::pair<bool, Channel>;

		class Manager
		{
		private:

			std::unordered_map<int, ChannelTuple> chMap;

		public:

			Manager()
			{
				int j = 1;
				for (int i = 0; i < numCh; i++)
				{
					chMap[j++] = std::make_pair(false, Channel());
				}
			}

			void createChannel(int chNum)
			{
				if (chNum == 0)
				{
					for (auto& ch : chMap)
					{
						if (ch.second.first == false)
						{
							ch.second.first = true;
							ch.second.second = Channel();
							break;
						}
					}
				}
				else
				{
					chMap[chNum] = std::make_pair(true, Channel());
				}
			}

			void deleteChannel(int chNum)
			{
				if (chMap.find(chNum) != chMap.end())
				{
					chMap.erase(chNum);
				}
				else
				{
					std::cout << "\t\t 해당 채널 존재 하지 않음.\n";
				}
			}

			void displayChannels()
			{
				std::cout << "\n\n";

				for (auto ch : chMap)
				{
					std::cout << "===========";
				}
				std::cout << "\n";

				for (auto ch : chMap)
				{
					std::cout << "=   CH " << ch.first << "  =";
				}
				std::cout << "\n";

				for (auto ch : chMap)
				{
					std::string onOff = ch.second.first ? "On    =" : "Off   =";
					std::cout << "=   " << onOff;

				}
				std::cout << "\n";

				for (auto ch : chMap)
				{
					std::cout << "===========";
				}
				std::cout << "\n";
			}
		};
	}

}


