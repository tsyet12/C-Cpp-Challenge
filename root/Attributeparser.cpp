/******************************************************************************

       Sin Yong Teng's Attempt to use C++ Attribute Parser

*******************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <iterator>



int main() {
    std::string first;
    std::getline(std::cin, first);
    std::istringstream iss(first);
    std::vector<int> tokens1;
    std::copy(std::istream_iterator<int> (iss),
                 std::istream_iterator<int>(),
                 std::back_inserter(tokens1));

    int n = tokens1[0], q=tokens1[1];
    std::string source;
    std::map<std::string, std::string> tagValue; 
    std::string tagKey;

    while( n > 0)
    {  
        std::string input;
        std::getline(std::cin, input);

        std::istringstream iss(input);
        std::vector<std::string> tokens;
        std::copy(std::istream_iterator<std::string> (iss), 
                   std::istream_iterator<std::string>(),
                   std::back_inserter(tokens));

        if( tokens.size() >=1)
        {
            std::string tag = tokens[0];
            if( tag[0] == '<' && tag[1] != '/')
            {

                if( tag[tag.size()-1]== '>')
                     tagKey.empty() ? tagKey = tag.substr(1,tag.size()-2):
                                      tagKey = tagKey+"."+tag.substr(1, tag.size()-2);
                else
                     tagKey.empty() ? tagKey = tag.substr(1):
                                      tagKey = tagKey+"."+tag.substr(1);  
            }
            if( tag[0] == '<' && tag[1] == '/')
            {
                auto found = tagKey.find_last_of(".");
                if( found != std::string::npos)
                   tagKey.erase(tagKey.begin()+found, tagKey.end());
                else
                   tagKey="";
            }            
        }
        if(tokens.size() > 1 )
        {  
            int i = 1;
            while( i+2 < tokens.size() )
            {        
                std::string name = tokens[i];
                std::string value = tokens[i+2];
                if( value[value.size()-1]== '>')
                    tagValue[tagKey+"~"+name] = value.substr(1, value.length()-3);
                else
                    tagValue[tagKey+"~"+name] = value.substr(1, value.length()-2);
                i+=3;
            }
        }
        --n;

    }

    std::string input1;
    while(  std::getline(std::cin, input1)) 
    {

        if( q < 0)
            break;
         std::istringstream iss(input1);
         std::vector<std::string> tokens;
         std::copy(std::istream_iterator<std::string> (iss), 
                   std::istream_iterator<std::string>(),
                   std::back_inserter(tokens));

         (tagValue.find(tokens[0]) != tagValue.end()) ? 
                                      std::cout<<tagValue[tokens[0]]<<"\n" :
                                      std::cout<<"Not Found!\n";
       --q; 
    }
}
