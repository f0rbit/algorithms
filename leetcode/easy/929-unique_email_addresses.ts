function numUniqueEmails(emails: string[]): number {
    const set = new Set<string>();

    for (const e of emails) {
        let [local, domain] = e.split("@");
        // remove the part between + and @
        const plus = local.indexOf('+');
        if (plus >= 0) local = local.substring(0, plus);
        local = local.replaceAll("\.", "");
        // remove all dots
        set.add(`${local}@${domain}`);
    }

    return set.size;
};
