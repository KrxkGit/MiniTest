#pragma once

#include <string>
#include <sstream>

class MiniTestException {
private:
	std::string m_fileName;
	unsigned int m_lineNumber;
protected:
	MiniTestException() = default;
public:
	MiniTestException(const std::string& fileName, unsigned int lineNum) : m_fileName(fileName), m_lineNumber(lineNum) {}
	std::string getFileName() const { return m_fileName; }
	unsigned int getLineNumber() const { return m_lineNumber; }
	std::string what() const {
		std::ostringstream oss;
		oss << "MiniTestException Raise here: " << m_fileName << ": " << m_lineNumber << std::endl;
		return oss.str();
	}
};