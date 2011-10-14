#! make

PROTOC = protoc
INPUTDIR = protocol

OUTDIR = generated
CPPOUT = $(OUTDIR)/cpp
PYTHONOUT = $(OUTDIR)/py

generate_command = $(PROTOC) --proto_path=$(INPUTDIR) --cpp_out=$(CPPOUT) --python_out=$(PYTHONOUT)

# Base names of all input files
inputs := Geometry Topology Vec3

stamps := $(patsubst %,$(OUTDIR)/%,$(inputs))

cpp_impls := $(patsubst %,$(CPPOUT)/%.pb.cc,$(inputs))
cpp_headers := $(patsubst %,$(CPPOUT)/%.pb.h,$(inputs))
py_outputs := $(patsubst %,$(PYTHONOUT)/%_pb2.py,$(inputs))

all: $(cpp_impls) $(cpp_headers)

$(cpp_impls): $(CPPOUT)/%.pb.cc : $(OUTDIR)/%
$(cpp_headers): $(CPPOUT)/%.pb.h : $(OUTDIR)/%

$(py_outputs): $(PYTHONOUT)/%_pb2.py : $(OUTDIR)/%

$(stamps): $(OUTDIR)/% : $(INPUTDIR)/%.proto $(OUTDIR)
	$(generate_command) $<
	@touch $@

# Generate dependency makefiles
#depends := $(patsubst %,$(STAMPDIR)/%.d,$(inputs)) 
#$(depends) : $(STAMPDIR)/%.d : $(INPUTDIR)/%.proto
#	grep '^include' $< | sed "s/[^\"]*\"\([^\"]*.proto\)\"/$($< :"

$(OUTDIR)/Geometry : $(OUTDIR)/Vec3
$(OUTDIR)/Topology : $(OUTDIR)/Vec3 $(OUTDIR)/Geometry

$(OUTDIR):
	mkdir -p $@

clean:
	-rm -rf $(stamps) $(cpp_impls) $(cpp_headers)

.PHONY: all clean
