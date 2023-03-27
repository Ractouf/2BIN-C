void parenthandler (int sig) {
	const* text = 'parent';
	write(1, text, strlen(text));

	alarm(12);
}

void childhandler (int sig) {
	const* text = 'child';
	write(1, text, strlen(text));

	alarm(5);
}

int main() {
	sigset_t set;

	sigemptyset(&set);
	sigaddset(&set, SIGALARM);
	sigaddset(&set, SIGUSR1);

	sigprocmask(SIG_BLOCK, &set, NULL);

	pid_t childID = fork();

	// PERE
	if (childID > 0) {
		
		sigaction(SIGALARM, parenthandler, NULL);
		sigprocmask(SIG_UNBLOCK, &set, NULL);

		while (true) {
			sleep(10);
		}
	}

	// FILS
	else {
		
		sigaction(SIGUSR1, childhandler, NULL);
		sigprocmask(SIG_UNBLOCK, &set, NULL);

		while (true) {
			sleep(10);
		}
	}
}