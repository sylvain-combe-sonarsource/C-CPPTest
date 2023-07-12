#include <stdio.h>

#define BUF_SIZE 100
#define AS_STRING "%99s"

// Use of a proper limit
int main() {
    char buffer[BUF_SIZE];
    // ok: scanf-formatspecifier-missing-width
    scanf("%99s", &buffer);
    // ok: scanf-formatspecifier-missing-width
    _tscanf(_T("%99s"), &buffer);
}

// Use of constant propagated value
int main() {
    char buffer[BUF_SIZE];
    char *format = "%99s";
    // ok: scanf-formatspecifier-missing-width
    scanf(format, &buffer);
    // ok: scanf-formatspecifier-missing-width
    _tscanf(_T(format), &buffer);
}

// Use of macro as format
int main() {
    char buffer[BUF_SIZE];
    // ok: scanf-formatspecifier-missing-width
    scanf(AS_STRING, &buffer);
    // ok: scanf-formatspecifier-missing-width
    _tscanf(_T(AS_STRING), &buffer);
}

// Standard use of %s or %[ (first parameter)
int main() {
    char buffer[BUF_SIZE];
    // ruleid: scanf-formatspecifier-missing-width
    scanf("%s", &buffer);
    // ruleid: scanf-formatspecifier-missing-width
    scanf("%[0-9]", &buffer);
    // ruleid: scanf-formatspecifier-missing-width
    _tscanf(_T("%s"), &buffer);
}

// Standard use of %s (second parameter)
int main() {
    char buffer[BUF_SIZE];
    // ruleid: scanf-formatspecifier-missing-width
    fscanf(stdin, "%s", &buffer);
    // ruleid: scanf-formatspecifier-missing-width
    _ftscanf(stdin, _T("%s"), &buffer);
}

// Use of constant propagated value
int main() {
    char buffer[BUF_SIZE];
    char *format = "%s";
    // ruleid: scanf-formatspecifier-missing-width
    scanf(format, &buffer);
    // ruleid: scanf-formatspecifier-missing-width
    _tscanf(_T(format), &buffer);
}

// Use of macro as format
// Currently a false negative
int main() {
    char buffer[BUF_SIZE];
    // todoruleid: scanf-formatspecifier-missing-width
    scanf(AS_STRING, &buffer);
    // todoruleid: scanf-formatspecifier-missing-width
    _tscanf(_T(AS_STRING), &buffer);
}

// Kind of a false positive, because the destination variables are being checked that the source will fit into them without using widths in the format specifiers.
// The second rule mentioned in the int-doc would take care of this.
void enshih_salangid(struct scrobicula_paradrop repositioned_kern)
{
    pthread_t stonesoup_t0, stonesoup_t1;
    struct stonesoup_data *stonesoupData;
  char *nonchivalrously_forbite = 0;
  ++stonesoup_global_variable;;
  nonchivalrously_forbite = ((char *)((struct scrobicula_paradrop )repositioned_kern) . paragogically_sphargis);
    tracepoint(stonesoup_trace, weakness_start, "CWE414", "A", "Missing Lock Check");
    stonesoupData = malloc(sizeof(struct stonesoup_data));
    if (stonesoupData) {
        stonesoupData->data = malloc(sizeof(char) * (strlen(nonchivalrously_forbite) + 1));
        stonesoupData->file1 = malloc(sizeof(char) * (strlen(nonchivalrously_forbite) + 1));
        stonesoupData->file2 = malloc(sizeof(char) * (strlen(nonchivalrously_forbite) + 1));
        if (stonesoupData->data && stonesoupData->file1 && stonesoupData->file2) {
            // todook: scanf-formatspecifier-missing-width
            if ((sscanf(nonchivalrously_forbite, "%d %s %s %s",
                      &(stonesoupData->qsize),
                        stonesoupData->file1,
                        stonesoupData->file2,
                        stonesoupData->data) == 4) &&
                (strlen(stonesoupData->data) != 0))
            {
                tracepoint(stonesoup_trace, variable_signed_integral, "stonesoupData->qsize", stonesoupData->qsize, &(stonesoupData->qsize), "INITIAL-STATE");
                tracepoint(stonesoup_trace, variable_buffer, "stonesoupData->data", stonesoupData->data, "INITIAL-STATE");
                tracepoint(stonesoup_trace, variable_buffer, "stonesoupData->file1", stonesoupData->file1, "INITIAL-STATE");
                tracepoint(stonesoup_trace, variable_buffer, "stonesoupData->file2", stonesoupData->file2, "INITIAL-STATE");
                if (pthread_mutex_init(&stonesoup_mutex, NULL) != 0) {
                    stonesoup_printf("Mutex failed to initilize.");
                }
                stonesoupData->data_size = strlen(stonesoupData->data);
                tracepoint(stonesoup_trace, trace_point, "Spawning threads.");
                if (pthread_create(&stonesoup_t0, NULL, delNonAlpha, (void *)stonesoupData) != 0) {
                    stonesoup_printf("Error creating thread 0.");
                }
                if (pthread_create(&stonesoup_t1, NULL, toCap, (void *)stonesoupData) != 0) {
                    stonesoup_printf("Error creating thread 1.");
                }
                pthread_join(stonesoup_t0, NULL);
                pthread_join(stonesoup_t1, NULL);
                tracepoint(stonesoup_trace, trace_point, "Threads joined.");
                stonesoup_printf("After joins.\n");
                pthread_mutex_destroy(&stonesoup_mutex);
            } else {
                stonesoup_printf("Error parsing input.\n");
            }
            free(stonesoupData->data);
        }
        free(stonesoupData);
    }
    tracepoint(stonesoup_trace, weakness_end);
;
  if (((struct scrobicula_paradrop )repositioned_kern) . paragogically_sphargis != 0) 
    free(((char *)((struct scrobicula_paradrop )repositioned_kern) . paragogically_sphargis));
stonesoup_close_printf_context();
}