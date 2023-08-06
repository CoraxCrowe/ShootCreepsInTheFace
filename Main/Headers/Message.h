#ifndef __CORAX_MESSAGE_H_
#define __CORAX_MESSAGE_H_

#include <string>

namespace Corax {
    class Message {
    public:
      std::string line1 = "Midway through the pathway of our years...";
      std::string line2 = "I found myself inside a forest dark...";
      std::string line3 = "Like man who from the righteous way steers... ";
      int lengthLine1 = std::size(line1);
      int lengthLine2 = std::size(line2);
      int lengthLine3 = std::size(line3);

      std::string addSpaces (std::string line, int lengthLine) {
        lengthLine = std::size(line);
        std::string tempLine;
        for (int i = 0; i < ((76 - lengthLine)/2); i++) {
          tempLine += " ";
        }
        tempLine += line + tempLine;
        if (lengthLine % 2 == 0) {
          tempLine += " ";
        }

        return tempLine;
      }

      void updateLines (std::string &line1, std::string &line2, std::string &line3) {
        line1 = addSpaces(line1, lengthLine1);
        line2 = addSpaces(line2, lengthLine2);
        line3 = addSpaces(line3, lengthLine3);
      }

  };
}

#endif