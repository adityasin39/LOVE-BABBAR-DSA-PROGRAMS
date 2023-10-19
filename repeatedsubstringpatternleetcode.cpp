//This approach will come up to mind if you have done string rotation problems.

// Intution: (orginal: https://leetcode.com/problems/repeated-substring-pattern/discuss/94344/Simple-Java-solution-2-lines/327797)
// If your string S contains a repeating substring, then this means you can "shift and wrap around" your string some number of times and have it match the original string.
// Example: abcabc
// Shift once: cabcab
// Shift twice: bcabca
// Shift three times: abcabc
// Now the string matches the original string, so you know there is a repeated substring.

// To avoid doing this weird wraparound and using modulo, you can just create a new string SS that is the original string concatenated with itself, and check if this new string contains the original string (shifted some number of times). However, you don't want it to match with the first half (S) and the second half (S), so you remove the first and last characters.
// The explanation for why that works is pretty straight forward.

// Consider a string S="helloworld". Now, given another string T="lloworldhe", can we figure out if T is a rotated version of S? Yes, we can! We check if S is a substring of T+T.

// Fine. How do we apply that to this problem? We consider every rotation of string S such that it's rotated by k units [k < len(S)] to the left. Specifically, we're looking at strings "elloworldh", "lloworldhe", "loworldhel", etc...

// If we have a string that is periodic (i.e. is made up of strings that are the same and repeat R times), then we can check if the string is equal to some rotation of itself, and if it is, then we know that the string is periodic. Checking if S is a sub-string of (S+S)[1:-1] basically checks if the string is present in a rotation of itself for all values of R such that 0 < R < len(S).
// I liked this solution and would like to explain this in a simple way.

// ss = (s + s)[1:-1]
// return ss.find(s) != -1

// The maximum length of a "repeated" substring that you could get from a string would be half it's length
// For example, s = "abcdabcd", "abcd" of len = 4, is the repeated substring.
// You cannot have a substring >(len(s)/2), that can be repeated.

// So, when ss = s + s , we will have atleast 4 parts of "repeated substring" in ss.
// (s+s)[1:-1], With this we are removing 1st char and last char => Out of 4 parts of repeated substring, 2 part will be gone (they will no longer have the same substring).
// ss.find(s) != -1, But still we have 2 parts out of which we can make s. And that's how ss should have s, if s has repeated substring.
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp=s+s;
        temp.erase(temp.begin());
        temp.erase(temp.end()-1);
        if(temp.find(s)!=string::npos) return true;
        return false;
    }
};