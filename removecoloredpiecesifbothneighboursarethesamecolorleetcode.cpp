class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice_turns=0;
        int bob_turns=0;
        for(int i=1;i<colors.size()-1;i++)
        {
            if(colors[i]=='A' && colors[i]==colors[i+1] && colors[i]==colors[i-1]) alice_turns++;
            else if(colors[i]=='B' && colors[i]==colors[i+1] && colors[i]==colors[i-1]) bob_turns++;
        }
        if(alice_turns<=bob_turns) return false;
        return true;
    }
};