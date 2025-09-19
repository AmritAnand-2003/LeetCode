class Spreadsheet {
    private int[][] excel;
    public Spreadsheet(int rows) {
        excel = new int[rows][26];
    }
    
    public void setCell(String cell, int value) {
        int col = cell.charAt(0) - 'A';
        int row = Integer.parseInt(cell.substring(1));
        excel[row - 1][col] = value;
    }
    
    public void resetCell(String cell) {
        int row = Integer.parseInt(cell.substring(1));
        int col = cell.charAt(0) - 'A';
        excel[row - 1][col] = 0;
    }
    
    public int getValue(String formula) {
        formula = formula.substring(1);
        String[] parts = formula.split("\\+");
        String left = parts[0], right = parts[1];
        boolean isLeftNumber = left.matches("\\d+");
        boolean isRightNumber = right.matches("\\d+");
        int leftNum, rightNum;
        if(!isLeftNumber){
            int row = Integer.parseInt(left.substring(1));
            int col = left.charAt(0) - 'A';
            leftNum = excel[row - 1][col];
        }
        else{
            leftNum = Integer.parseInt(left);
        }
        if(!isRightNumber){
            int row = Integer.parseInt(right.substring(1));
            int col = right.charAt(0) - 'A';
            rightNum = excel[row - 1][col];
        }
        else{
            rightNum = Integer.parseInt(right);
        }
        return leftNum + rightNum;
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet obj = new Spreadsheet(rows);
 * obj.setCell(cell,value);
 * obj.resetCell(cell);
 * int param_3 = obj.getValue(formula);
 */