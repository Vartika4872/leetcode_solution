class Solution {
public:
string toHex(int num) {
    if (num == 0) return "0";
    
    string hex = "0123456789abcdef";
    string result = "";
    
    // process at most 8 hex digits (32 bits)
    while (num != 0 && result.length() < 8) {
        int last4bits = num & 15;   // extract last 4 bits
        result = hex[last4bits] + result;
        num >>= 4;                 // shift right by 4 bits
    }
    
    return result;
}
};