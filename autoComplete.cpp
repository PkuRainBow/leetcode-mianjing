/**
I am referring to the algorithm that is used to give query suggestions when a user types a search term in Google.

I am mainly interested in how Google's algorithm is able to show: 1. Most important results (most likely queries rather than anything that matches) 2. Match substrings 3. Fuzzy matches

I know you could use Trie or generalized trie to find matches, but it wouldn't meet the above requirements...

Similar questions asked earlier 
**/


For (heh) awesome fuzzy/partial string matching algorithms, check out Damn Cool Algorithms:

http://blog.notdot.net/2007/4/Damn-Cool-Algorithms-Part-1-BK-Trees
http://blog.notdot.net/2010/07/Damn-Cool-Algorithms-Levenshtein-Automata
These don't replace tries, but rather prevent brute-force lookups in tries - which is still a huge win. Next, you probably want a way to bound the size of the trie:

keep a trie of recent/top N words used globally;
for each user, keep a trie of recent/top N words for that user.
Finally, you want to prevent lookups whenever possible...

cache lookup results: if the user clicks through on any search results, you can serve those very quickly and then asynchronously fetch the full partial/fuzzy lookup.
precompute lookup results: if the user has typed "appl", they are likely to continue with "apple", "apply".
prefetch data: for instance, a web app can send a smaller set of results to the browser, small enough to make brute-force searching in JS viable.