class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coord) {
        if(coord.size() == 2) return true;
        else {
            bool m_inf = (coord[1][0] - coord[0][0]) == 0;

            double m;
            if(!m_inf) m = (double)(coord[1][1] - coord[0][1])/(double)(coord[1][0] - coord[0][0]);

            int x1 = coord[0][0];
            int y1 = coord[0][1];

            for(int i=2; i<coord.size(); i++) {
                int x=coord[i][0];
                int y=coord[i][1];
                if(m_inf) {
                    if(x!=x1) return false;
                } else if((m*x) - (m*x1) != y - y1) return false;

            }

            return true;
        }
    }
};