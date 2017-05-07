s/tk busy/byzi/
s/ \\fBtk$// ; s/^busy\\fR/\\fBbyzi\\fR/
s/TH busy n "" Tk "Tk Built-In Commands"/TH byzi n "" Tk "Tk Extension Command"/
s/busy \\- confine/byzi \\- confine/
/\\fBbyzi\\fR \\fIwindow/i\
\\fBpackage\\fR \\fBrequire\\fR \\fIbyzi\\fR\
.sp\
\\fBnamespace\\fR \\fBimport\\fR \\fI::byzi::byzi\\fR\
.sp
