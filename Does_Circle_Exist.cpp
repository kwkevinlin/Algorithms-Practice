/*
 * Given a string as command, determine if the command results in a path that leads back to the origin.
 *
 * Possible inputs:
 *    G, L, R
 *        G = Go (forward) one unit
 *        L = Face left, but don't move
 *        R = Face right, but don't move
 *
 * Example:
 *    GLGLGLG
 *     
 * Explanation:
 *    Starting facing north, go north one square. Then, turn left (facing west now) and go forward one
 *    square. Turn left again, then go forward one square. Turn left again, then go forward one square.
 *    The commands lead back to the origin point, and thus a circle exists. 
 *
 */
string doesCircleExist(string commands) {
    
    int x = 0, y = 0; //Origin coordinates
    char directions = 'n'; //Direction I'm facing
    
    for (int i = 0; i < commands.length(); i++) {
             
        //For {n, e, s, w} directions, check command
        if (directions == 'n') {
            if (commands[i] == 'G') { //If 'G', move forward one with respect to current direction
                y++;
            } else if (commands[i] == 'L') { //If 'L', turn left with respect to current direction
                directions = 'w';
            } else if (commands[i] == 'R') { //If 'R', turn right with respect to current direction
                directions = 'e';
            }
        } else if (directions == 'e') {
            if (commands[i] == 'G') {
                x++;
            } else if (commands[i] == 'L') {
                directions = 'n';
            } else if (commands[i] == 'R') {
                directions = 's';
            }
        } else if (directions == 'w') {
            if (commands[i] == 'G') {
                x--;
            } else if (commands[i] == 'L') {
                directions = 's';
            } else if (commands[i] == 'R') {
                directions = 'n';
            }
        } else if (directions == 's') {
            if (commands[i] == 'G') {
                y--;
            } else if (commands[i] == 'L') {
                directions = 'e';
            } else if (commands[i] == 'R') {
                directions = 'w';
            }
        }
        
    }
  
    //If back to original location
    if (x == 0 && y == 0) {
        return "YES";
    } else {
        return "NO";
    }

}