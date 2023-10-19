// if you dont understand then refer to kreakemp solution
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diagonalmoves=min(abs(fx-sx),abs(fy-sy));
        int extramoves=max(abs(fx-sx),abs(fy-sy))-diagonalmoves;
        int totalmoves=diagonalmoves+extramoves;
        if(sx==fx && sy==fy && t==1) return false;
        if(totalmoves<=t) return true;
        return false;
    }
};