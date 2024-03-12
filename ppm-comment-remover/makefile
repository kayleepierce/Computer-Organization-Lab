CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS =

SRCS = ppmDriver.c ppmUtil.c
OBJS = $(SRCS:.c=.o)
TARGET = ppmConverter

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS) $(TARGET)
