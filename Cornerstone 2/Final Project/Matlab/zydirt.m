% Zhenming (Mark) Yang
% Soil Sampler
pHA_id = fopen('pHA.txt','r');        % Open data files
B2A_id = fopen('B2A.txt','r');
formatSpec = '%f';
size = [20 20];
pHA = fscanf(pHA_id,formatSpec, size);
B2A = fscanf(B2A_id,formatSpec, size);
[pHA_avg, B2A_avg, pHA_min, pHA_max, B2A_min, B2A_max] = matrix_calc(pHA, B2A);        % Calculate the average, minimum, maximum of pHA and B2A matrixes
fprintf("Average of pHA: %.2f\nAverage of B2A: %.2f\nMinimum of pHA: %.2f\nMaximum of pHA: %.2f\nMinimum of B2A: %.2f\nMaximum of B2A: %.2f\n", pHA_avg, B2A_avg, pHA_min, pHA_max, B2A_min, B2A_max);  % report result

X = 1:20;          % Initialize X, Y axis and the plot layout
Y = 1:20;
tiledlayout(2,2)

nexttile;
mesh(X,Y,pHA(X,Y));     % First mesh graph with pH Level
title('pH Level by Location');
xlabel('x');
ylabel('y');
zlabel('pH Level')

nexttile;
mesh(X,Y,B2A(X,Y));     % Second mesh graph with B2 Level
title('B2 Level by Location');
xlabel('x');
ylabel('y');
zlabel('B2 Level')

nexttile([1 2]);        % Final plot with pH Level vs. B2 Level
plot(pHA(:), B2A(:), '.');
title('pH Level vs. B2 Level');
xlabel('pH Level');
ylabel('B2 Level');

%%
% Functions
function [pHA_avg, B2A_avg, pHA_min, pHA_max, B2A_min, B2A_max] = matrix_calc(pHA, B2A)
    pHA_sum = 0;           % Initialize the variables
    B2A_sum = 0;
    B2A_min = 1;
    B2A_max = 1;
    pHA_min = 4.5;
    pHA_max = 4.5;
    for row = 1:20          % Loop through the Matrix row by row and column by column
        for column = 1:20
            pHA_sum = pHA_sum + pHA(row,column);        % Get the sum of the Matrix
            B2A_sum = B2A_sum + B2A(row,column);
            if B2A_min > B2A(row,column)            % Check if the B2A maximum and minimum still holds
                B2A_min = B2A(row,column);
            end
            if B2A_max < B2A(row,column)
                B2A_max = B2A(row,column);
            end
            if pHA_min > pHA(row,column)            % Check if the pHA maximum and minimum still holds
                pHA_min = pHA(row,column);
            end
            if pHA_max < pHA(row,column)
                pHA_max = pHA(row,column);
            end
        end
    end
    pHA_avg = pHA_sum/400;      % Sum divided by the number of entries to get average
    B2A_avg = B2A_sum/400;
end