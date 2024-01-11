number_of_terms = input('Enter the number of terms desired: ');

sum = 0;

for i=1:number_of_terms

    sum = sum+1/(i^2);

end

fprintf('\nThe sum is %-5.4f\n', sum)