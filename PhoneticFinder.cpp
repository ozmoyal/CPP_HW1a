#include <string>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include "PhoneticFinder.hpp"
using namespace std;

namespace phonetic{
    
    int swapLetter(char a1 , char a2)
    {
        if((a1>='A')&&(a1<='Z'))
        {
            a1=a1+32;
        }
           if((a2>='A')&&(a2<='Z'))
        {
            a2=a2+32;
        }
        if(a1==a2) return 1;
        //v,w case
        if(((a1=='v') && (a2=='w'))||((a1=='w') && (a2=='v')))
        return 1;
        //g,j case
         if(((a1=='g') && (a2=='j'))||((a1=='j') && (a2=='g')))
        return 1;
          //s,z case
         if(((a1=='s') && (a2=='z'))||((a1=='z') && (a2=='s')))
        return 1;
         // d, t case
         if(((a1=='d') && (a2=='t'))||((a1=='t') && (a2=='d')))
        return 1;
         // o,u case
         if(((a1=='o') && (a2=='u'))||((a1=='o') && (a2=='u')))
        return 1;
          // i,y case
         if(((a1=='i') && (a2=='y'))||((a1=='y') && (a2=='i')))
        return 1;
        // b, f, p case 
        if(((a1=='b') &&((a2=='f') ||(a2=='p'))) || ((a1=='f') &&((a2=='b') ||(a2=='p'))) ||
        ((a1=='p') &&((a2=='f') ||(a2=='b')))) return 1;
         // c, k, q case 
        if(((a1=='c') &&((a2=='k') ||(a2=='q'))) || ((a1=='k') &&((a2=='c') ||(a2=='q'))) ||
        ((a1=='q') &&((a2=='k') ||(a2=='c')))) return 1;
        //ERE 
        return 0;
    }

int equalWord(string a , string b)
    {
        if(a.size()!=b.size()) return 0;
        for(int i=0;i<a.size();i++)
        {
            if(swapLetter(a.at(i),b.at(i))==0)
            return 0;
        }
        return 1;
    }

    string find(string text , string word){
   if (word.size()==0) throw out_of_range("ERR, empty word");
   for(int i=0;i<word.size();i++)
   {
   if(isspace(word.at(i)))  throw out_of_range("ERR, more then one word");
   }
   string ans="";
   for (int i=0;i<text.size();i++)
   {
       while((i<text.size() )&&(!isspace(text.at(i))))
       {
           ans=ans+text.at(i);
           i++;
       }
       if(equalWord(ans,word)) return ans;
       ans="";
   }
   throw out_of_range("ERR, the word is'nt in the txt");
}
}