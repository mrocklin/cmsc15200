
// I will include comments that show the problems with this code


// There is no explanatory comment
int power(int a, int b) // variable names are not descriptive
{
int i=0;// All of these lines should be indented one tab
int result=1;
while(i<b){
result=result*a;      i=i+1;} // These lines should be indented an additional tab. 
                              // Also, there should not be two statements in
                              // one line
return result;
}
