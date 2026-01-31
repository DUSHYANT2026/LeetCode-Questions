// class Solution {
// public:
//     vector<string> addOperators(string num, int target) {
        
//     }
// };


class Solution {
public:
    std::vector<std::string> results;
    std::string num_str; // Store num as a member for easier access
    long long target_val; // Store target as a long long for consistency with intermediate calculations

    // Backtracking function
    // index: The current starting position in num_str for the number being formed.
    // current_eval: The current evaluated value of the expression built so far.
    // prev_operand: The value of the last operand added/subtracted/multiplied. Crucial for '*' precedence.
    // current_exp_str: The string representation of the expression built so far.
    void backtrack(int index,
                   long long current_eval,
                   long long prev_operand,
                   std::string current_exp_str) {

        // Base Case: All digits from num_str have been processed
        if (index == num_str.length()) {
            // If the final evaluated value matches the target, add the expression to results.
            if (current_eval == target_val) {
                results.push_back(current_exp_str);
            }
            return;
        }

        // Iterate to form the current number, starting from num_str[index]
        // 'i' represents the end index of the current number string (inclusive).
        for (int i = index; i < num_str.length(); ++i) {
            // Handle leading zeros:
            // If the current number string being formed has more than one digit (i.e., i > index)
            // AND its first digit is '0' (i.e., num_str[index] == '0'), then it's an invalid number
            // (e.g., "01", "007"). We must stop forming longer numbers from this 'index'.
            // A single "0" is valid, so this check doesn't trigger if i == index.
            if (i > index && num_str[index] == '0') {
                break; 
            }

            // Extract the current number substring and convert it to a long long.
            std::string current_num_str = num_str.substr(index, i - index + 1);
            long long current_num = std::stoll(current_num_str);

            // First number case: No operator is prefixed.
            if (index == 0) {
                // Start a new path:
                // next_index = i + 1 (move past the current number)
                // next_current_eval = current_num (the first number is the initial evaluation)
                // next_prev_operand = current_num (this number is the first and last operand)
                // next_current_exp_str = current_num_str
                backtrack(i + 1, current_num, current_num, current_num_str);
            } else {
                // Subsequent numbers: Try inserting '+', '-', or '*'

                // Option 1: Add '+' operator
                // Update current_eval by adding current_num.
                // The new prev_operand is current_num.
                backtrack(i + 1, current_eval + current_num, current_num, current_exp_str + "+" + current_num_str);

                // Option 2: Add '-' operator
                // Update current_eval by subtracting current_num.
                // The new prev_operand is -current_num (important for subsequent '*' operations).
                backtrack(i + 1, current_eval - current_num, -current_num, current_exp_str + "-" + current_num_str);

                // Option 3: Add '*' operator
                // Multiplication has higher precedence.
                // If the current expression is conceptually "A + B", and we add "* C",
                // it should become "A + (B * C)".
                // Here, `current_eval` holds "A + B", and `prev_operand` holds "B".
                // To get "A", we calculate `current_eval - prev_operand`.
                // Then, we add the new product `(prev_operand * current_num)` to "A".
                // The new prev_operand becomes this product `(prev_operand * current_num)`.
                backtrack(i + 1, current_eval - prev_operand + (prev_operand * current_num), prev_operand * current_num, current_exp_str + "*" + current_num_str);
            }
        }
    }

    // Main function to add operators
    vector<string> addOperators(std::string num, int target) {
        num_str = num;
        target_val = target; // Assign target (int) to long long member
        results.clear();     // Clear results from any previous calls

        if (num_str.empty()) {
            return results;
        }

        // Initiate the backtracking process.
        // Start from index 0.
        // Initial current_eval, prev_operand, and current_exp_str are 0 and empty,
        // as the first number will initialize them.
        backtrack(0, 0, 0, ""); 
        return results;
    }
};
