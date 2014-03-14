CC = gcc

TARGET = check_count

SOURCES = check_count.c utils.c mynode.c

HEADERS = .

OBJS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

.c.o:
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJS) $(TARGET) *~

depend: $(SOURCES)
	makedepend $(HEADERS) $^

# DO NOT DELETE THIS LINE -- make depend needs it
