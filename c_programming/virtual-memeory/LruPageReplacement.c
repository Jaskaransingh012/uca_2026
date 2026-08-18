#include <stdio.h>
#include <stdbool.h>

void simulate_lru(int page_requests[], int num_requests, int num_frames) {
    int frames[num_frames];
    int last_used[num_frames];
    int page_faults = 0;

    // Initialize all frames as empty
    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }

    for (int time = 0; time < num_requests; time++) {

        int page = page_requests[time];
        bool hit = false;

        // ------------------------------------------------
        // TODO 1: Check for HIT
        // ------------------------------------------------
        for (int i = 0; i < num_frames; i++) {

            if (frames[i] == page) {
                hit = true;

                // Page was used at this time
                last_used[i] = time;

                break;
            }
        }

        // ------------------------------------------------
        // TODO 2: Handle PAGE FAULT
        // ------------------------------------------------
        if (!hit) {

            page_faults++;

            int replace_index = -1;

            // First look for an empty frame
            for (int i = 0; i < num_frames; i++) {
                if (frames[i] == -1) {
                    replace_index = i;
                    break;
                }
            }

            // If no empty frame, find LRU page
            if (replace_index == -1) {

                int oldest_time = last_used[0];
                replace_index = 0;

                for (int i = 1; i < num_frames; i++) {

                    if (last_used[i] < oldest_time) {
                        oldest_time = last_used[i];
                        replace_index = i;
                    }
                }
            }

            // Put new page into selected frame
            frames[replace_index] = page;
            last_used[replace_index] = time;
        }

        // Print current RAM state
        printf("Request %d: %s  [", page, hit ? "HIT" : "FAULT");

        for (int i = 0; i < num_frames; i++) {
            if (frames[i] == -1)
                printf("-");
            else
                printf("%d", frames[i]);

            if (i < num_frames - 1)
                printf(", ");
        }

        printf("]\n");
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
}

int main() {

    int requests[] = {
        1, 2, 3, 4, 1, 2,
        5, 1, 2, 3, 4, 5
    };

    int num_requests =
        sizeof(requests) / sizeof(requests[0]);

    simulate_lru(requests, num_requests, 3);

    return 0;
}
