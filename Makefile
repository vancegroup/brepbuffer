#! make

PROTOC = protoc
INPUTDIR = protocol
CPPOUT = generated/cpp
PYTHONOUT = generated/py
STAMPDIR = generated


generate_command = $(PROTOC) --proto_path=$(INPUTDIR) --cpp_out=$(CPPOUT) #--python_out=$(PYTHONOUT)

# Base names of all input files
inputs := Geometry Topology Vec3

stamps := $(patsubst %,$(STAMPDIR)/%,$(inputs))

cpp_impls := $(patsubst %,$(CPPOUT)/%.pb.cc,$(inputs))
cpp_headers := $(patsubst %,$(CPPOUT)/%.pb.h,$(inputs))

all: $(cpp_impls) $(cpp_headers)


$(cpp_impls): $(CPPOUT)/%.pb.cc : $(STAMPDIR)/%
$(cpp_headers): $(CPPOUT)/%.pb.h : $(STAMPDIR)/%

$(stamps): $(STAMPDIR)/% : $(INPUTDIR)/%.proto $(STAMPDIR) $(CPPOUT) $(PYTHONOUT)
	$(generate_command) $<
	@touch $@

$(CPPOUT) $(PYTHONOUT) $(STAMPDIR):
	mkdir -p $@

clean:
	-rm -rf $(stamps) $(cpp_impls) $(cpp_headers)

.PHONY: all clean
