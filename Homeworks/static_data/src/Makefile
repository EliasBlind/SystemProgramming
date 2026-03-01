CPPCHECK = cppcheck
HEADERS_DIR = headers
REPORT_FILE = report.xml

all:
	@echo "Доступные команды:"
	@echo "  make task3_1  - Анализ всего проекта (C++20, отчет XML)"
	@echo "  make task3_2  - Анализ forty_two.c (C89, без unusedFunction)"
	@echo "  make task3_3  - Анализ legacy_code.c (с путями к headers)"

task3_1:
	$(CPPCHECK) --std=c++20 --xml --xml-version=2 . 2> $(REPORT_FILE)

task3_2:
	$(CPPCHECK) --std=c89 --disable=unusedFunction --library=std forty_two.c

task3_3:
	$(CPPCHECK) -I $(HEADERS_DIR) legacy_code.c

clean:
	rm -f $(REPORT_FILE)
