class Solution {
public:
    bool isValid(string s) {
         
         stack<char> tmpstack;
         
         for( int i = 0 ; i <= s.size()-1; i++)
         {
                if( s[i] == '(' || s[i] == '[' || s[i] == '{' )
                    tmpstack.push( s[i] );
                else
                    {
                        if( s[i] == ')')
                            if ( tmpstack.size() != 0 && tmpstack.top() == '(' )
                            {
                                tmpstack.pop();
                            }
                            else return false;
                        
                        if( s[i] == ']')
                            if ( tmpstack.size() != 0 && tmpstack.top() == '[')
                            {
                                tmpstack.pop();
                            }
                            else return false;
                        
                        if( s[i] == '}')
                            if ( tmpstack.size() != 0 && tmpstack.top() == '{')
                            {
                                tmpstack.pop();
                            }
                            else return false;
                    }
         }
         
         if( tmpstack.size()!= 0) return false;
         return true;
    }
};