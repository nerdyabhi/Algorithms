class Solution
{
public:
    string customSortString(string order, string s)
    {
        int arr[26] = {0};
        string ans;

        /* easy peasy approach by lord abhi himself

        1. first store all the character in a frequency array
        2. Now print the elements in order string first with their frequency as well
        3. erase their frequency's as well
        3. Now print the remaining elements in the array

        */

        for (int i = 0; i < s.length(); i++)
            arr[s[i] - 'a']++; // you know exactly what i am doing

        for (int i = 0; i < order.length(); i++)
        {
            int freq = arr[order[i] - 'a'];
            ans.append(freq, order[i]);
            arr[order[i] - 'a'] = 0;
        }

        for (int i = 0; i < 26; i++)
        {
            if (arr[i])
                ans.append(arr[i], i + 'a');
        }

        return ans;
    }
};