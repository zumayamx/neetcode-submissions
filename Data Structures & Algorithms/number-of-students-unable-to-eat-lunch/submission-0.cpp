class Solution {
   public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int totalStudents = students.size();
        vector<int> preference(2);

        for (int& s : students) {
            preference[s]++;
        }

        for (int& s : sandwiches) {
            if (preference[s] > 0) {
                preference[s]--;
                totalStudents--;
            } else
                break;
        }

        return totalStudents;
    }
};