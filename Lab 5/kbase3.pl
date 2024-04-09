%empty list
zeros([], 0).
%if first list item is 0, count eachtime you have 0, counter
zeros([0 | T], Z) :- zeros(T, Z1), Z is Z1 + 1.
%if first item is not 0, keep counting 0 in the list
zeros([_ | T], Z) :- zeros(T, Z). 

%?- zeros([ ], X). 
%X=0
%?- zeros([1, 0, 0, 5], X).
%X=2