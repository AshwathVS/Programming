import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

// For understanding precedence based parsing!
class Parser {
    Map<String, Integer> precedenceMap = Map.of(
        "+", 1, "-", 1,
        "*", 2, "/", 2,
        "^", 3
    );

    Map<String, Boolean> isRightAssociative = Map.of(
        "+", false, "-", false,
        "*", false, "/", false,
        "^", true
    );

    String currentToken;
    Iterator<String> tokens;

    Parser(Iterator<String> tokens) {
        this.tokens = tokens;
        this.currentToken = tokens.hasNext() ? tokens.next() : null;
    }

    Node parseExpression(int minPrecedence) {
        Node left = parseFactor();

        while (null != currentToken && currentTokenIsOperator() && precedenceOf(currentToken) >= minPrecedence) {
            String operator = currentToken;
            int precedence = precedenceOf(operator);
            int nextPrecedence = isRightAssociative(operator) ? precedence : precedence + 1;

            consumeToken(); // Move to the next token
            Node right = parseExpression(nextPrecedence);

            left = new Node(operator, left, right);
        }

        return left;
    }

    Node parseFactor() {
        if (currentToken.equals("(")) {
            consumeToken();
            Node expression = parseExpression(0);
            consumeToken();
            return expression;
        } else {
            return parseIdentifierOrLiteral();
        }
    }

    boolean currentTokenIsOperator() {
        return precedenceMap.containsKey(currentToken);
    }

    int precedenceOf(String operator) {
        return precedenceMap.getOrDefault(operator, 0);
    }

    boolean isRightAssociative(String operator) {
        return isRightAssociative.getOrDefault(operator, false);
    }

    void consumeToken() {
        currentToken = tokens.hasNext() ? tokens.next() : null;
    }

    Node parseIdentifierOrLiteral() {
        Node node = new Node(currentToken); // Create a leaf node
        consumeToken(); // Advance
        return node;
    }

    public static void main(String[] args) {
        // Input expression as a list of tokens
        String expression = "a ^ b * c";
        List<String> tokens = tokenize(expression);

        // Create the parser with the tokenized input
        Parser parser = new Parser(tokens.iterator());

        // Parse the expression
        Node ast = parser.parseExpression(0);

        // Print the resulting Abstract Syntax Tree (AST)
        System.out.println("Parsed AST:");
        printAST(ast, 0);
    }

    // Tokenize the input string into a list of tokens
    private static List<String> tokenize(String input) {
        // Split by spaces for simplicity
        return Arrays.asList(input.split("\\s+"));
    }

    // Recursively print the AST for debugging
    private static void printAST(Node node, int depth) {
        if (node == null) return;

        // Indent to represent tree depth
        for (int i = 0; i < depth; i++) {
            System.out.print("  ");
        }

        // Print current node
        System.out.println(node.value);

        // Print left and right children
        printAST(node.left, depth + 1);
        printAST(node.right, depth + 1);
    }
}

class Node {
    String value;
    Node left, right;

    Node(String value) { this.value = value; }
    Node(String value, Node left, Node right) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}
