/*
A word is considered valid if:

It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.

Notes:

'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.
Leetcode 3136
*/

class Solution {
    public char[] vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    public boolean isValid(String word) {
        boolean containsVowel = false;
        boolean containsConsonant = false;
        if(word.length() < 3)return false;
        for(int i=0;i<word.length();++i){
            if(!isLetter(word.charAt(i))){
                if(word.charAt(i) < '0' || word.charAt(i) > '9')return false;
                else continue;
            }
            else{
                if(isVowel(word.charAt(i)))containsVowel=true;
                else{
                containsConsonant=true;
                }
            }
        }
        return containsVowel && containsConsonant;
    }
    public boolean isVowel(char symbol){
        for(int i =0;i<vowels.length;++i){
            if(symbol == vowels[i])return true;
        }
        return false;
    }
    public boolean isLetter(char symbol){
        if(symbol < 'a' || symbol > 'z'){
            if(symbol < 'A' || symbol > 'Z'){
                return false;
            }
        }
        return true;
    }
}
