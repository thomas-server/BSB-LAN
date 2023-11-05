#!/usr/bin/perl

# This script retrieves all settings from the heater (optionally limted to a
# range limited by the first two command line arguments) and stores them in a
# CSV-style file.
# All you need to do is adjust the URL of BSB-LAN in the line below (including
# any potential credentials/passcode). Do NOT end the URL with a slash!

# Prompt for IP and port
print "Enter the IP address and port of the BSB-LAN device (e.g., '192.168.1.90/80'): ";
my $ip_port = <STDIN>;
chomp($ip_port);
my $URL = "http://$ip_port";

my $from = $ARGV[0];
my $to = $ARGV[1];
if ($from le " " ) {
  $from = 0;
}
if ($to le " " ) {
  $to = 9999;
}


# Prompt for credentials
print "Username: ";
my $username = <STDIN>;
chomp($username);

print "Password: ";
system "stty -echo";  # Disable echo for password input
my $password = <STDIN>;
chomp($password);
system "stty echo";  # Re-enable echo
print "\n";  # Print a newline since echo was disabled when the user pressed enter


print "Creating backup for parameters $from to $to, this may take several minutes...\n";
my $date = `date "+%Y%m%d"`;
chomp ($date);

open(my $OUT, ">", "backup_settings-$from-$to-$date.csv") or die "Cannot open file: $!";

# Construct and execute the wget command while printing it
my $wget_cmd = "wget --http-user='$username' --http-password='$password' -q -O - $URL/$from-$to";
print "Executing wget command: $wget_cmd\n";
open(my $WGET, "-|", $wget_cmd) or die "Cannot execute wget: $!";

while (my $line=<WGET>) {
  if ($line =~ /^\s*(\d+)\s+.*: (.*)/) {
    my $param_no = $1;
    my $param_val = $2;
    if ($param_val =~ /error/) {
      next;
    }
    print "$param_no;$param_val\n";
    print OUT "$param_no;$param_val\n";
  }
}

print "Backup completed.\n";
