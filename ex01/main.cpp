
#include "Span.hpp"

Span val10m(MAX_VAL);

int main() {
	writeAndBuildSpan();
	testSpanOperations();
	testExceptions();
	testRangeAndIndex();
	return 0;
}

std::string intToStr(int val) {
    std::stringstream ss;
    ss << val;
    return ss.str();
}

void writeAndBuildSpan() {
    std::ofstream outFile("logs", std::ios::trunc);
    if (!outFile) {
        std::cerr << "ERROR: Unable to open file: logs" << std::endl;
        return;
    }

    std::string content;
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        int val = rand();
        val10m.addNumber(val);
        content += "[" + intToStr(i) + "]" + intToStr(val) + "\n";
    }
    outFile << content;
    outFile.close();
}

void testSpanOperations() {
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "min: " << sp.getValMin() << std::endl;
    std::cout << "max: " << sp.getValMax() << std::endl;
    std::cout << GREEN << "testSpanOperations: OK[✅]!" << RESET << std::endl;
}

void testExceptions() {
    Span spn;
    try {
        spn.addNumber(10);
    } catch (std::exception &e) {
        assert(std::string(e.what()) == "ERROR: Invalid Arg");
    }

    Span spn2(1);
    spn2.addNumber(10);
    try {
        spn2.shortestSpan();
    } catch (std::exception &e) {
        assert(std::string(e.what()) == "ERROR: There are not enough numbers");
    }
    std::cout << GREEN << "testExceptions: OK[✅]!" << RESET << std::endl;
}

void testRangeAndIndex() {
    Span spn10m(MAX_VAL);
    spn10m.addRange(val10m.begin(), val10m.end() - MAX_VAL / 2);
    spn10m.addRange(val10m.end() - MAX_VAL / 2, val10m.end());

    assert(spn10m.getValMax() == val10m.getValMax());
    assert(spn10m.getValMin() == val10m.getValMin());
    assert(*spn10m.begin() == *val10m.begin());
    std::cout << GREEN << "testRangeAndIndex: OK[✅]!" << RESET << std::endl;
}
