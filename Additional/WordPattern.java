/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.
Leetcode 290
*/

class Solution {
    public boolean wordPattern(String pattern, String s) {
        Map<Character, String> table = new HashMap<>();
        int index = 0;
        StringBuilder current = new StringBuilder();
        s = new String(s + ' ');
        for(int i = 0; i<s.length();++i){
            if(s.charAt(i) != ' '){
                current.append(s.charAt(i));
            }
            else{
                String newString = current.toString();
                try{
                if(table.containsKey(pattern.charAt(index))){
                    if(!newString.equals(table.get(pattern.charAt(index)))){
                        return false;
                    }
                }
                else{
                    if(table.containsValue(newString))return false;
                    table.put(pattern.charAt(index), newString);
                }
                current = new StringBuilder();
                index++;
                }
                catch(Exception e){
                    return false;
                }
            }
        }
        return index == pattern.length();
    }
}
