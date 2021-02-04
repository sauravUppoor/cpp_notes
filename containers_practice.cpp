#include<cstdlib>
#include<vector>
#include<string>
#include<iostream>
#include<numeric>
#include<sstream>

// Function prototypes
std::vector<std::string> StringToVector(std::string input, char del);

std::string VectorToString(std::vector<std::string> input, char del);

std::string TrimeWhitespaces(std::string);

std::vector<int> FindStringMatches(std::string, std::string);

std::string ReplaceSubstring(std::string, std::string, std::string);

std::string CaesarCipher(std::string, int, bool);

int main()
{
    // 1. String to Vector of strings separated by a character delimiter
    std::string sentence = "This is a random string.";
    std::vector<std::string> vec = StringToVector(sentence, ' ');

    for(auto &s: vec)
    {
        std::cout << s << '\n';
    }

    // 2. Vector of strings to String
    std::vector<std::string> sCusts = {"Bob", "Alice", "Tom"};
    std::string cust = VectorToString(sCusts, ' ');

    std::cout << cust << '\n';

    // 3. Trim white spaces from start and end
    std::string aStr = "         This is a string            ";
    aStr = TrimeWhitespaces(aStr);
    std::cout << aStr << '\n';

    // 4. Find string matches
    std::string phrase = "to be or not to be";
    std::vector<int> matches = FindStringMatches(phrase, "be");
    for(auto &m: matches)
        std::cout << m << '\n';

    // 5. Replace all substring
    std::string pReplace = "This is new string new";
    pReplace = ReplaceSubstring(pReplace, "new", "x");
    std::cout << pReplace << '\n';

    // 6. Check if a character is upper, lower, digit or space
    char alpha = 'a';
    char dig = '0';
    char space = ' ';
    std::cout << isalpha(alpha) << '\n'; // 1/nonzero
    std::cout << isupper(alpha) << '\n'; // 0
    std::cout << islower(alpha) << '\n'; // 1/nz
    std::cout << isdigit(dig) << '\n'; // nz
    std::cout << isspace(space) << '\n'; // nz

    // 7. Caesar Cipher
    // true --> encrypt, false --> decrypt

    std::string theString = "Convert this thing.";
    theString = CaesarCipher(theString, 5, true);
    std::cout << theString << '\n';
    theString = CaesarCipher(theString, 5, false);
    std::cout << theString << '\n';
}

std::vector<std::string> StringToVector(std::string input, char del)
{
    std::stringstream ss(input);
    std::string sIndvString;

    std::vector<std::string> vecWords;
    while(getline(ss, sIndvString, del))
    {
        vecWords.push_back(sIndvString);
    }
    
    return vecWords;
}

std::string VectorToString(std::vector<std::string> input, char del)
{
    std::string custs = "";
    for(auto &c: input)
    {
        custs += c;
        custs += del;
    }
    return custs;
}

std::string TrimeWhitespaces(std::string theString)
{
    std::string whitespaces = " \t\r\f\n ";
    theString.erase(theString.find_last_not_of(whitespaces)+1);
    std::cout << theString << '\n';
    theString.erase(0, theString.find_first_not_of(whitespaces));
    return theString;
}

std::vector<int> FindStringMatches(std::string theString, std::string sample)
{
    std::vector<int> matches;
    int idx = theString.find(sample, 0);
    while(idx != std::string::npos)
    {
        matches.push_back(idx);
        idx = theString.find(sample, idx+1);
    }
    return matches;
}

std::string ReplaceSubstring(std::string theString, std::string old, std::string    newString)
{
    std::vector<int> matches = FindStringMatches(theString, old);
    if(matches.size() != 0)
    {
        int lenDiff = newString.size() - old.size();
        int loopCnt = 0;
        for(auto idx: matches)
        {
            theString.replace(idx + (loopCnt * lenDiff),
                        old.size(), 
                        newString);
            loopCnt++;
            std::cout << theString << '\n';
        }
    }
    return theString;
}

std::string CaesarCipher(std::string theString, int value, bool enc)
{
    if(enc)
    {
        for(auto &character: theString)
            character = (character + value);
    }
    else 
    {
        for(auto &character: theString)
            character = (character - value);
    }
    return theString;
}