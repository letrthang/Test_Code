/*
 * MostThreePage.cpp
 *
 *  Created on: Mar 15, 2015
 *      Author: thangle
 */

#include <iostream>
#include <cstdlib>
#include <list>
#include <map>

using namespace std;
struct Record {
	int user_id;
	int page_id;
};

string three_hits = "";
list<Record> records;
map<int, list<int> > map_hit;
map<string, int> map_t_hits; // 3 hits and count

int main() {

	Record r1, r2, r3, r4;
	r1.user_id = 1;
	r1.page_id = 1;
	records.push_back(r1);
	r1.user_id = 1;
	r1.page_id = 2;
	records.push_back(r1);
	r1.user_id = 1;
	r1.page_id = 3;
	records.push_back(r1);

	r2.user_id = 2;
	r2.page_id = 1;
	records.push_back(r2);
	r2.user_id = 2;
	r2.page_id = 2;
	records.push_back(r2);
	r2.user_id = 2;
	r2.page_id = 3;
	records.push_back(r2);

	r3.user_id = 3;
	r3.page_id = 4;
	records.push_back(r3);
	r3.user_id = 3;
	r3.page_id = 5;
	records.push_back(r3);
	r3.user_id = 3;
	r3.page_id = 6;
	records.push_back(r3);

	r4.user_id = 4;
	r4.page_id = 7;
	records.push_back(r4);
	r4.user_id = 4;
	r4.page_id = 8;
	records.push_back(r4);
	r4.user_id = 4;
	r4.page_id = 9;
	records.push_back(r4);

	for (Record r : records) {
		if (map_hit.count(r.user_id) > 0) {
			map_hit[r.user_id].push_back(r.page_id); // add page ID to map

			if (map_hit[r.user_id].size() == 3) // user browsed 3 pages
					{

				list<int> tmp = map_hit[r.user_id];
				list<int>::iterator it = tmp.begin();

				three_hits += *it;
				three_hits += "->";
				three_hits += *(it++);
				three_hits += "->";
				three_hits = *(it++);

				if (map_t_hits.count(three_hits) > 0) {
					map_t_hits[three_hits]++;
				} else {
					map_t_hits[three_hits] = 1;
				}

				map_hit[r.user_id].clear(); // clean page
			}

		} else // user ID is not exist in map
		{
			list<int> tmp;
			tmp.push_back(r.page_id);
			map_hit[r.user_id] = tmp; // add new user ID to map
		}

	}

	// sort the 2nd element of map_t_hits
	map<string, int>::iterator it;
	int max_count = 0;
	string max_t_hits;
	for (it = map_t_hits.begin(); it != map_t_hits.end(); it++) {
		if (it->second > max_count) {
			max_count = it->second;
			max_t_hits = it->first;
		}
	}

	// display most 3 pages
	cout << "most 3 pages: " << max_t_hits << "\n";
}

