#include <bits/stdc++.h>

using namespace std;

void search(string input, regex rules, string token){
  smatch matches;
  vector<string> shiam; 
  int ctr = 0;
  while(regex_search(input, matches, rules)){
    shiam.push_back(matches[0]);
    ctr++;
    input = matches.suffix().str();
  }

  cout<<token<<" ("<<ctr<<")\t: ";
  for(int i=0; i<shiam.size(); i++){
    cout<<shiam[i]<<" ";
  }
  cout<<endl;
  return;
}

int main(){
  string input;
  input = "float a = (b*c) + a1  % 10  / int(-3.1416);";

  regex constantRegex("(\\+|\\-)?\\b\\d+(\\.\\d+)?\\b");
  regex keywordRegex("\\b(auto|break|case|class|catch|const|continue|default|do|double|else|enum|explicit|export|extern|float|for|friend|goto|if|inline|int|long|namespace|new|operator|private|protected|public|register|return|short|signed|sizeof|static|string|struct|switch|template|this|throw|typedef|union|unsigned|using|virtual|void|volatile|cout|endl|while)\\b");
  regex operatorRegex("(\\+|-|\\*|/|%|==|=|!=|<=|>=|<|>|<<|>>)+(?!\\d)");
  regex punctuationRegex("[#$',:;?@^_`|~]");
  regex parenthesisRegex("[()|{}|\\[\\]]");
  regex identifierRegex("\\b(?!auto|break|case|class|catch|const|continue|default|do|double|else|enum|explicit|export|extern|float|for|friend|goto|if|inline|int|long|namespace|new|operator|private|protected|public|register|return|short|signed|sizeof|static|string|struct|switch|template|this|throw|typedef|union|unsigned|using|virtual|void|volatile|while)\\b[a-zA-Z_]+[a-zA-Z0-9_]*");
  
  cout<< "------ ShiamSharif-0032 ------";
  cout<<endl;
  cout<<endl;
  
  search(input, keywordRegex, "Keyword");
  search(input, identifierRegex, "Identifier");
  search(input, operatorRegex, "Operator");
  search(input, constantRegex, "Constant");
  search(input, punctuationRegex, "Punctuation");
  search(input, parenthesisRegex, "Parenthesis");

  return 0;
}
