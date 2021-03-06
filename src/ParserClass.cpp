/**
 * This software is released under the terms of the MIT License
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @copyright  2009-2012 Roberto Perpuly
 * @license    http://www.opensource.org/licenses/mit-license.php The MIT License
 */
#include <pelet/ParserClass.h>
#include <pelet/TokenClass.h>
#include <pelet/FullParserObserverClass.h>
#include <pelet/ResourceParserObserverClass.h>
#include <stack>

/* 
 * generated by Bison according to the prefix of our choosing
 * Bison won't put this declaration in the header file so we must
 * manually make it available here by using "extern"
 */
extern int php53_lint_parse(pelet::LexicalAnalyzerClass &analyzer);
extern int php54_lint_parse(pelet::LexicalAnalyzerClass &analyzer);

extern int php53_resource_parse(pelet::LexicalAnalyzerClass &analyzer, pelet::ResourceParserObserverClass& observers);
extern int php54_resource_parse(pelet::LexicalAnalyzerClass &analyzer, pelet::ResourceParserObserverClass& observers);

pelet::ParserClass::ParserClass()
	: Lexer()
	, ClassObserver(0)
	, ClassMemberObserver(0)
	, FunctionObserver(0)
	, VariableObserver(0)
	, ExpressionObserver(0) {
	SetVersion(pelet::PHP_53);
}

bool pelet::ParserClass::ScanFile(const std::string& file, pelet::LintResultsClass& results) {
	bool ret = false;
	if (Lexer.OpenFile(file)) {
		pelet::FullParserObserverClass observers(ClassObserver, ClassMemberObserver, FunctionObserver, VariableObserver, ExpressionObserver);
		if (pelet::PHP_53 == Version && !VariableObserver && !ExpressionObserver) {
			pelet::ResourceParserObserverClass rObservers(ClassObserver, ClassMemberObserver, FunctionObserver);
			ret = php53_resource_parse(Lexer, rObservers) == 0;
			results.Scope = rObservers.GetScope();
		}
		else if (pelet::PHP_54 == Version && !VariableObserver && !ExpressionObserver) {
			pelet::ResourceParserObserverClass rObservers(ClassObserver, ClassMemberObserver, FunctionObserver);
			ret = php54_resource_parse(Lexer, rObservers) == 0;
			results.Scope = rObservers.GetScope();
		}
		else if (pelet::PHP_53 == Version) {
			ret = php53parse(Lexer, observers) == 0;
			results.Scope = observers.CurrentScope();
		}
		else if (pelet::PHP_54 == Version) {
			ret = php54parse(Lexer, observers) == 0;
			results.Scope = observers.CurrentScope();
		}
		results.Error = Lexer.ParserError;
		results.File = file;
		results.LineNumber = Lexer.GetLineNumber();
		results.CharacterPosition = Lexer.GetCharacterPosition();
		Close();
	}
	return ret;
}

bool pelet::ParserClass::ScanFile(FILE* file, const UnicodeString& filename, pelet::LintResultsClass& results) {
	bool ret = false;
	if (Lexer.OpenFile(file)) {
		pelet::FullParserObserverClass observers(ClassObserver, ClassMemberObserver, FunctionObserver, VariableObserver, ExpressionObserver);
		if (pelet::PHP_53 == Version && !VariableObserver && !ExpressionObserver) {
			pelet::ResourceParserObserverClass rObservers(ClassObserver, ClassMemberObserver, FunctionObserver);
			ret = php53_resource_parse(Lexer, rObservers) == 0;
			results.Scope = rObservers.GetScope();
		}
		else if (pelet::PHP_54 == Version && !VariableObserver && !ExpressionObserver) {
			pelet::ResourceParserObserverClass rObservers(ClassObserver, ClassMemberObserver, FunctionObserver);
			ret = php54_resource_parse(Lexer, rObservers) == 0;
			results.Scope = rObservers.GetScope();
		}
		else if (pelet::PHP_53 == Version) {
			ret = php53parse(Lexer, observers) == 0;
			results.Scope = observers.CurrentScope();
		}
		else if (pelet::PHP_54 == Version) {
			ret = php54parse(Lexer, observers) == 0;
			results.Scope = observers.CurrentScope();
		}
		results.Error = Lexer.ParserError;
		results.UnicodeFilename = filename;
		results.LineNumber = Lexer.GetLineNumber();
		results.CharacterPosition = Lexer.GetCharacterPosition();
		Close();
	}
	return ret;
}

bool pelet::ParserClass::ScanString(const UnicodeString& code, pelet::LintResultsClass& results) {
	bool ret = false;
	if (Lexer.OpenString(code)) {
		pelet::FullParserObserverClass observers(ClassObserver, ClassMemberObserver, FunctionObserver, VariableObserver, ExpressionObserver);
		if (pelet::PHP_53 == Version && !VariableObserver && !ExpressionObserver) {
			pelet::ResourceParserObserverClass rObservers(ClassObserver, ClassMemberObserver, FunctionObserver);
			ret = php53_resource_parse(Lexer, rObservers) == 0;
			results.Scope = rObservers.GetScope();
		}
		else if (pelet::PHP_54 == Version && !VariableObserver && !ExpressionObserver) {
			pelet::ResourceParserObserverClass rObservers(ClassObserver, ClassMemberObserver, FunctionObserver);
			ret = php54_resource_parse(Lexer, rObservers) == 0;
			results.Scope = rObservers.GetScope();
		}
		else if (pelet::PHP_53 == Version) {
			ret = php53parse(Lexer, observers) == 0;
			results.Scope = observers.CurrentScope();
		}
		else if (pelet::PHP_54 == Version) {
			ret = php54parse(Lexer, observers) == 0;
			results.Scope = observers.CurrentScope();
		}
		results.Error = Lexer.ParserError;
		results.File = "";
		
		results.LineNumber = Lexer.GetLineNumber();
		results.CharacterPosition = Lexer.GetCharacterPosition();
		Close();
	}
	return ret;
}

void pelet::ParserClass::SetVersion(pelet::Versions version) {
	Version = version;
	Lexer.SetVersion(Version);
}

void pelet::ParserClass::SetClassMemberObserver(ClassMemberObserverClass* observer) {
	ClassMemberObserver = observer;
}

void pelet::ParserClass::SetClassObserver(ClassObserverClass* observer) {
	ClassObserver = observer;
}

void pelet::ParserClass::SetFunctionObserver(FunctionObserverClass* observer) {
	FunctionObserver = observer;
}

void pelet::ParserClass::SetVariableObserver(VariableObserverClass* observer) {
	VariableObserver = observer;
}

void pelet::ParserClass::SetExpressionObserver(ExpressionObserverClass* observer) {
	ExpressionObserver = observer;
}

bool pelet::ParserClass::LintFile(const std::string& file, LintResultsClass& results) {
	bool ret = false;
	if (Lexer.OpenFile(file)) {
		if (pelet::PHP_53 == Version) {
			ret = php53_lint_parse(Lexer) == 0;
		}
		else if (pelet::PHP_54 == Version) {
			ret = php54_lint_parse(Lexer) == 0;
		}
		results.Error = Lexer.ParserError;
		results.File = file;
		results.LineNumber = Lexer.GetLineNumber();
		///results.Scope = observers.CurrentScope();
		results.CharacterPosition = Lexer.GetCharacterPosition();
		Lexer.Close();
	}
	return ret;
}

bool pelet::ParserClass::LintFile(FILE* file, const UnicodeString& filename, LintResultsClass& results) {
	bool ret = false;
	if (Lexer.OpenFile(file)) {
		if (pelet::PHP_53 == Version) {
			ret = php53_lint_parse(Lexer) == 0;
		}
		else if (pelet::PHP_54 == Version) {
			ret = php54_lint_parse(Lexer) == 0;
		}
		results.Error = Lexer.ParserError;
		results.UnicodeFilename = filename;
		///results.Scope = observers.CurrentScope();
		results.LineNumber = Lexer.GetLineNumber();
		results.CharacterPosition = Lexer.GetCharacterPosition();
		Lexer.Close();
	}
	return ret;
}

bool pelet::ParserClass::LintString(const UnicodeString& code, LintResultsClass& results) {
	bool ret = false;
	if (Lexer.OpenString(code)) {
		if (pelet::PHP_53 == Version) {
			ret = php53_lint_parse(Lexer) == 0;
		}
		else if (pelet::PHP_54 == Version) {
			ret = php54_lint_parse(Lexer) == 0;
		}
		results.Error = Lexer.ParserError;
		results.File = "";
		///results.Scope = observers.CurrentScope();
		results.LineNumber = Lexer.GetLineNumber();
		results.CharacterPosition = Lexer.GetCharacterPosition();
		Lexer.Close();
	}
	return ret;
}

int pelet::ParserClass::GetCharacterPosition() const {
	return Lexer.GetCharacterPosition();
}

void pelet::ParserClass::Close() {
	Lexer.Close();
}


namespace pelet {

class ParserVariableObserverClass : public ExpressionObserverClass {

private:
	
	// only needed because variable constructor requires it
	pelet::ScopeClass Scope;

public:

	pelet::VariableClass Variable;

	ParserVariableObserverClass() 
	: Scope()
	, Variable(Scope) {

	}
	
	void ExpressionVariableFound(pelet::VariableClass* expression) {
		for (size_t i = 0; i < expression->ChainList.size(); ++i) {
			
			// don't copy expression pointers from CallArguments or ArrayAccess, 
			// as they will be no good
			// after the observer goes out of scope
			std::vector<pelet::ExpressionClass*> emptyArgs;
			Variable.AppendToChain(expression->ChainList[i].Name, 
				emptyArgs, expression->ChainList[i].IsFunction, 
				expression->ChainList[i].IsStatic);
			Variable.ChainList.back().IsArrayAccess = expression->ChainList[i].IsArrayAccess; 
		}
	}

	void ExpressionScalarFound(pelet::ScalarExpressionClass* expression) {
		Variable.AppendToChain(expression->Value);
	}

	void ExpressionNewInstanceFound(pelet::NewInstanceExpressionClass* expression) {
		Variable.AppendToChain(expression->ClassName);
		Variable.ExpressionType = expression->ExpressionType;
		for (size_t i = 0; i < expression->ChainList.size(); ++i) {
			
			// don't copy expression pointers, as they will be no good
			// after the observer goes out of scope
			std::vector<pelet::ExpressionClass*> emptyArgs;
			Variable.AppendToChain(expression->ChainList[i].Name, emptyArgs, expression->ChainList[i].IsFunction, expression->ChainList[i].IsStatic);
		}
	}
};

}

void pelet::ParserClass::ParseExpression(UnicodeString expressionString, pelet::VariableClass& variable) {
	expressionString.trim();

	// remove the operators if they are at the end; this prevents parse errors
	bool endsWithObject = false;
	bool endsWithStatic = false;
	bool endsWithNamespace = false;
	if (expressionString.endsWith(UNICODE_STRING_SIMPLE("->"))) {
		expressionString.remove(expressionString.length() - 2, 2);
		endsWithObject = true;
	}
	if (expressionString.endsWith(UNICODE_STRING_SIMPLE("::"))) {
		expressionString.remove(expressionString.length() - 2, 2);
		endsWithStatic = true;
	}
	if (expressionString.endsWith(UNICODE_STRING_SIMPLE("\\"))) {
		expressionString.remove(expressionString.length() - 1, 1);
		endsWithNamespace = true;
	}

	// make it so that the expression observer is always called by terminating the expression
	if (!expressionString.endsWith(UNICODE_STRING_SIMPLE(";"))) {
		expressionString += UNICODE_STRING_SIMPLE(";");
	}
	variable.Clear();

	pelet::ParserVariableObserverClass localObserver;
	pelet::FullParserObserverClass observers(NULL, NULL, NULL, NULL, &localObserver);

	// parse the given expression code snippet
	// most of the time, the expression observer will NOT be called because 
	// the expression observer is only called for assignment expressions
	// but we want this method to be able to parse a single expression
	if (Lexer.OpenString(expressionString)) {	
		if (pelet::PHP_53 == Version) {
			php53parse(Lexer, observers);
		}
		else if (pelet::PHP_54 == Version) {
			php54parse(Lexer, observers);
		}
		Lexer.Close();
	}
	variable.Copy(localObserver.Variable);
	if (endsWithObject) {
		std::vector<pelet::ExpressionClass*> args;
		variable.AppendToChain(UNICODE_STRING_SIMPLE(""), args, false, false);
	}
	if (endsWithStatic) {
		std::vector<pelet::ExpressionClass*> args;
		variable.AppendToChain(UNICODE_STRING_SIMPLE(""), args, false, true);
	}
	if (endsWithNamespace) {
		if (!variable.ChainList.empty()) {
			variable.ChainList[0].Name += UNICODE_STRING_SIMPLE("\\");
		}
	}
}

pelet::LintResultsClass::LintResultsClass()
	: Error()
	, File()
	, UnicodeFilename()
	, Scope()
	, LineNumber(0)
	, CharacterPosition(0) {
}

void pelet::LintResultsClass::Copy(const pelet::LintResultsClass& other) {
	Error = other.Error;
	File = other.File;
	UnicodeFilename = other.UnicodeFilename;
	Scope = other.Scope;
	LineNumber = other.LineNumber;
	CharacterPosition = other.CharacterPosition;
}

void pelet::LintResultsClass::Clear() {
	Error.remove();
	UnicodeFilename.remove();
	Scope.Clear();
	File = "";
	LineNumber = 0;
	CharacterPosition = 0;
}
