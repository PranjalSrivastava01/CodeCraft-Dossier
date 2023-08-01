function reverseString(str)
{
    let reverseStr='';
    for(let i=str.length-1;i>=0;i--)
    {
        reverseStr=reverseStr+str[i];
    }
    return reverseStr;
}
const originalStr='Navigation';
const reverseStrin=reverseString(originalStr);
console.log(reverseStrin);