# Butler

A CLI tool to manage your to-dos.

### USAGE
butler [category] [task] {options}

## Contributing and Tweaking
Below is some info about how butler does its job in case you want to contribute or tweak.

### Storing Events
Events are stored in $HOME/.butler/events, in the format DATE;NAME;TIME;LOCATION;COLOR, where date of the format YYYYMMDD.
As of now, events stored in this file will be sorted by date when the program terminates. The events file should be backed up when opened.
