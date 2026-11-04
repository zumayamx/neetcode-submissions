// input = [[0,2],[2,0],[2,2]]
// distanceIndex = [{2, 0},{2, 1},{2.8, 2}]
// sortByDistance(distanceIndex, 0, 2)
// start = 0, end = 2;
// 2 - 0 + 1 = 3, continue the code.
// pivot = distanceIndex[2].first = 2.8
// left = 0;
// i goes from 0 to 2 (inclusive)
// i = 0, first iteration
// distanceIndex[0].first = 2
// 2 < 2.8, yes inner code is executed
// tmp = distanceIndex[0] = {2, 0}
// distanceIndex[0] = distanceIndex[0] = {2, 0}
// distanceIndex[0] = tmp = {2, 0}
// left ++ = 1
// i = 1, next iteration
// ocurrs the same, left = 2
// swap the pivot, nothing happens


class Solution {
private:
    void sortByDistance(vector<pair<float, int>>& distanceIndex, int start, int end)
    {
        if (end - start + 1 <= 1) return;
        float pivot = distanceIndex[end].first;
        int left = start;

        cout << "sortByDistance(" << start << ", " << end << ") pivot=" << pivot << "\n";

        for (int i = start; i <= end - 1; i++)
        {
            if (distanceIndex[i].first < pivot)
            {
                pair<float, int> tmp = distanceIndex[left];
                distanceIndex[left] = distanceIndex[i];
                distanceIndex[i] = tmp;
                left++;
            }
        }

        pair<float, int> tmp = distanceIndex[left];
        distanceIndex[left] = distanceIndex[end];
        distanceIndex[end] = tmp;

        sortByDistance(distanceIndex, start, left - 1);
        sortByDistance(distanceIndex, left + 1, end);
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<float, int>> distanceIndex;
        for (int i = 0; i < (int)points.size(); i++)
        {
            float distance =  sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            distanceIndex.push_back({distance, i});
        }

        sortByDistance(distanceIndex, 0, (int)distanceIndex.size() - 1);

        for (auto& p : distanceIndex) cout << p.first << " " << p.second << " "; cout << "\n";

        vector<vector<int>> result;
        for (int i = 0; i < k; i++)
        {
            vector<int> e = points[distanceIndex[i].second];
            result.push_back(e);
        }

        return result;
    }
};
